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
	char buffer[5];
        Mat img = imread("IMG_6379.JPG");
	int font_face = cv::FONT_HERSHEY_COMPLEX;
        double font_scale = 2;
        int thickness = 2;
        int baseline;
        int l=0;
        string text1;
	gcvt(sarg, 3, buffer);
	text1 = buffer;
        //strstream ss;
        //ss << sarg;
        //ss >> text1;
        Size text_size = getTextSize(text1, font_face, font_scale, thickness, &baseline);
        Point origin;
        origin.x = 100;
        origin.y = 100;
	putText(img, text1, origin, font_face, font_scale, Scalar(0, 255, 255), thickness,8,0);
        imshow("colorim", img);
        waitKey(30);
        //pthread_exit(NULL);
}


int main()
{
	//typedef chrono::duration<int,ratio<1,0.1>> 0s;
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
	begin = chrono::steady_clock::now();
	while(true)
	{
	//	sleep(0.005);
		point = chrono::steady_clock::now();
		spend = chrono::duration_cast<chrono::milliseconds>(point - begin);
		time1 = spend.count()/0.1;
	//	cout << time1 <<endl;
		time2 = time1*0.1;
		if(ptime1/10 != time1/10) //terminal output
		{	
			cout << time1/10 << endl;
			ptime1 = time1;
		}
		if(ptime2 != time2) //wimdow output
		{
			time2s[i] = time2;
			pthread_t tids[NUM_THREADS];
			pthread_create(&tids[i], NULL, op, (void*)&(time2s[i]));
			i++;
			ptime2 = time2;
		}
	//	cout << "i=" << i << endl;
	//	i++;
	}
}
