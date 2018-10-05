//#include <iostream>
//#include <pthread.h>
//#include <string>
#include "timer.h"

using namespace std;

int main()
{
	char choice[8];
	cout << "[INFO] Welcome to the counter." << endl;
	&Timer::open();
	pthread_t ids[100];
	int l;
	while(true)
	{
		cin >> choice;
		if(choice=="start")
		{
			cout << "[INFO] Start counting." << endl;
			pthread_create(&ids[l], NULL, Timer::startTiming, NULL);
			l++;
		}	
		if(choice=="pause")
		{
			cout << "[INFO] Paused." << endl;
			pthread_create(&ids[l], NULL, Timer::pause, NULL);
			l++;
		}
		if(choice=="resume")
		{
			cout << "[INFO] Resumed." << endl;
			pthread_create(&ids[l], NULL, Timer::resume, NULL);
			l++;
		}
		if(choice== "stop")
		{
			cout << "[INFO] Stop counting." << endl;
			pthread_create(&ids[l], NULL, Timer::stopTiming, NULL);
			l++;
		}
		if(choice== "quit")
		{
			cout << "[INFO] Program exited." << endl;
			pthread_create(&ids[l], NULL, Timer::close, NULL);
			l++;
		}
	}
}


