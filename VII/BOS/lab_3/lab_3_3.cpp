#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc == 2 && strcmp(argv[1], "\\?") == 0)
	{
		cout << "СПРАВКА:\n\n";
		cout << "Создать консольное приложение, которое создает не менее 3-х потоков управления,\n";
		cout << "каждый поток управления периодически выводит на консоль определенную разработчиком фразу:\n";
		cout << "Автор: Воробьева Н. О.  БИс-41\n\n";
	}
	else if(argc >= 2)
	{
		cout << "PID РОДИТЕЛЬСКОГО ПРОЦЕССА:" << getpid() << endl;
		pid_t pid = fork();
    		
		if(pid == 0)
    		{
			cout << "PID ДОЧЕРНЕГО ПРОЦЕССА:" << getpid() << endl;
        		execv(argv[1], argv);
          	}
	}
	return 0;
}

//g++ -o lab_3_3 lab_3_3.cpp
//
//./lab_3_3 "\?"
//
//./lab_3_3 "launch" "hello world"
