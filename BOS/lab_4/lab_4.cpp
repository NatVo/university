#include <string.h>

#include "lab_4.h"

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
	else if (argc == 2 && strcmp(argv[1], "\\d") == 0)
	{

		list_drivers();

	}

	else if(argc == 2 && strcmp(argv[1], "") != 0)
	{
		string one_service = argv[1];
		list_service(true, one_service);
	}
	else
	{
		string one_service = "";
		list_service(false, one_service);
	}

	return 0;
}

//g++ -o lab_4 lab_4.cpp lab_4_func.cpp
//
//./lab_4 "\?"
//
//./lab_4 "\d"
//
//./lab_4
//
//./lab_4 "User"
