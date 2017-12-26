#include <fstream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <stdio.h>
#include <mutex>

#include "lab_5.h"

int N = 10;
int counter;

mutex g_lock;

bool check_launch()
{
	bool FLAG = true;
	ifstream pidfile("/var/run/lab_5_pid.txt");
	if (pidfile)
	{
		std::cout << "ПРОЦЕСС УЖЕ ЗАПУЩЕН!" << std::endl;
	}
	else
	{
		ofstream pidfile("/var/run/lab_5_pid.txt");
		pidfile.close();
		FLAG = false;
	}
	return FLAG;
}

void end_proc()
{
	remove("/var/run/lab_5_pid.txt");
}

void thread_info(int id)
{
	cout << "ПОТОК - " << id <<  " НАЧАЛ РАБОТУ" << endl;
	int rand_number = rand() % 350000 + 300000;
     	g_lock.lock();
 	
	cout << "БЛОКИРОВАНИЕ MUTEX ПОТОКА - " << id << endl;
     	//std::this_thread::sleep_for(std::chrono::seconds(rand()%10));
     	usleep(rand_number);
	cout << "РАЗБЛОКИРОВАНИЕ MUTEX ПОТОКА - " << id << endl;
 
     	g_lock.unlock();
}
 
int start_threads()
{
     	//srand((unsigned int)time(0));
     	thread t1(thread_info, 1);
     	thread t2(thread_info, 2);
     	thread t3(thread_info, 3);
	thread t4(thread_info, 4);     	
        thread t5(thread_info, 5);

	t1.join();
     	t2.join();
     	t3.join();
	t4.join();
	t5.join();
     	return 0;
}


















