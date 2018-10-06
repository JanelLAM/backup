#include <iostream>
#include <chrono>
#include <iomanip>
#include <unistd.h>
#include <cstdlib>
#include <pthread.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define NUM_THREADS 1000

void* op(void* args)
{
        double sarg = *((double*)args);
	char buffer[7];
        Mat img = imread("IMG_6379.JPG");
	int font_face = cv::FONT_HERSHEY_COMPLEX;
        double font_scale = 2;
        int thickness = 2;
        int baseline;
        string text1;
	gcvt(sarg, 4, buffer);
	text1 = buffer;
        Size text_size = getTextSize(text1, font_face, font_scale, thickness, &baseline);
        Point origin;
        origin.x = 100;
        origin.y = 100;
	putText(img, text1, origin, font_face, font_scale, Scalar(0, 255, 255), thickness,8,0);
        imshow("colorim", img);
        waitKey(30);
}


int main()
{
	typedef chrono::duration<double> dr;
	typedef chrono::steady_clock::time_point tp;

	tp begin;
	tp point;
	tp end;
	dr spend=dr(0);
	int time1=0, ptime1 =2;
	double time2, ptime2 =2;
	int i=0;
	double time2s[100];
	pthread_t tids[NUM_THREADS];
	begin = chrono::steady_clock::now();
	cout << "[INFO] Welcome to the counter." << endl;
	cout << "[INFO] Start counting." << endl;
	while(true)
	{	
		point = chrono::steady_clock::now();
		spend = chrono::duration_cast<chrono::milliseconds>(point - begin);
		time1 = spend.count()/0.1;
		time2 = time1*0.1;
		if(ptime1/10 != time1/10) //terminal output
		{	
			cout << time1/10 << endl;
			ptime1 = time1;
		}
		if(ptime2 != time2) //wimdow output
		{
			time2s[i] = time2;
			pthread_create(&tids[i], NULL, op, (void*)&(time2s[i]));
			i++;
			ptime2 = time2;
		}
		if(ptime1/10 == 5) //pause and resume
		{
			cout << "[INFO] Paused." << endl;
                        point = std::chrono::steady_clock::now();
		        pthread_create(&tids[i], NULL, op, (void*)&(time2s[i-1]));
			i=i+2;
			sleep(3);
			cout << "[INFO] Resumed." << endl; //resume
                	tp point2 = std::chrono::steady_clock::now();
        		begin = point2 - point + begin;
        		while(true)
        		{
                		point = chrono::steady_clock::now();
                		spend = chrono::duration_cast<chrono::milliseconds>(point - begin);
                		time1 = spend.count()/0.1;
				time2 = time1*0.1;
                		if(ptime1/10 != time1/10) //terminal output
                		{
                        		cout << time1/10 << endl;
                        		ptime1 = time1;
                		}
                		if(ptime2 != time2) //wimdow output
                		{
                        		time2s[i] = time2;
                        		pthread_create(&tids[i], NULL, op, (void*)&(time2s[i]));
                        		i++;
                        		ptime2 = time2;
				}
				if(ptime1/10 == 7) //stop and quit
				{
					time2s[i]=0;
					cout << "[INFO] Stop counting." << endl;
					pthread_create(&tids[i], NULL, op, (void*)&(time2s[i]));
                        		cout << "test";
					i++;
					sleep(3);
					cout << "[INFO] Program exited." << endl;
                        		pthread_exit(NULL);
				}
			}
		}
	}
}
