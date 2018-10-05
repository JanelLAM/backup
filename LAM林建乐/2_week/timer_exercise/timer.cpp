//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <pthread.h>
//#include <cstdlib>
//#include <iomanip>
#include "timer.h"
//#include <string>

using namespace cv;

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
        std::string text1;
        gcvt(sarg, 3, buffer);
        text1 = buffer;
        Size text_size = getTextSize(text1, font_face, font_scale, thickness, &baseline);
        Point origin;
        origin.x = 100;
        origin.y = 100;
        putText(img, text1, origin, font_face, font_scale, Scalar(0, 255, 255), thickness,8,0);
        imshow("Timer", img);
        waitKey(30);
}

void* Timer::open(void* args)
{
	pthread_create(&tids[i], NULL, op, NULL);
	i++;
}

void* Timer::startTiming(void* args)
{
	
	begin = std::chrono::steady_clock::now();
	while(true)
	{
		point = std::chrono::steady_clock::now();
		spend = std::chrono::duration_cast<std::chrono::milliseconds>(point - begin);
		time1 = spend.count()/0.1;
		if(ptime1 != time1) //terminal output
		{
			std::cout << time1 << std::endl;
			ptime1 = time1;
		}
		if(ptime2 != time2) //wimdow output
		{
			time2s[i] = time2;
			pthread_create(&tids[i], NULL, op, (void*)&(time2s[i]));
			i++;
			ptime2 = time2;
		}
	}
}
	
void* Timer::stopTiming(void* args)
{
	pthread_create(&tids[i], NULL, op, NULL);
	i++;
}

void* Timer::close(void* args)
{
	pthread_exit(NULL);
}

void* Timer::pause(void* args)
{
	point = std::chrono::steady_clock::now();
	pthread_create(&tids[i], NULL, op, (void*)&(time2s[i]));
	i++;
}

void* Timer::resume(void* args)
{
	tp point2 = std::chrono::steady_clock::now();
	begin = point2 - point + begin;
	while(true)
        {
                point = std::chrono::steady_clock::now();
                spend = std::chrono::duration_cast<std::chrono::milliseconds>(point - begin);
                time1 = spend.count()/0.1;
                if(ptime1 != time1) //terminal output
                {
                        std::cout << time1 << std::endl;
                        ptime1 = time1;
                }
                if(ptime2 != time2) //wimdow output
                {
                        time2s[i] = time2;
                        pthread_create(&tids[i], NULL, op, (void*)&(time2s[i]));
                        i++;
                        ptime2 = time2;
                }
        }

}

