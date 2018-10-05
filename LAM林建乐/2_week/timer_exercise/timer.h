#ifndef TIMER_H_
#define TIMER_H_
#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <pthread.h>
#include <cstdlib>
#include <iomanip>
#include <string>

typedef std::chrono::steady_clock::time_point tp;
typedef std::chrono::duration<double> dr;

class Timer
{
	private:
	static tp begin;
	static tp point;
	static tp end;
	static dr spend;
	static int time1, ptime1;
	static double time2, ptime2;
	static double time2s[1000];
	static pthread_t tids[1000];
	static int i;
	public:
	static void* open(void* args);
	static void* startTiming(void* args);
	static void* stopTiming(void* args);
	static void* close(void* args);
	static void* pause(void* args);
	static void* resume(void* args);
};

#endif
