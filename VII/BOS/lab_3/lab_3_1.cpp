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
		cout << "Автор: Воробьева Н. О.  БИс-41\n\n";
	}
	else if(argc >= 2)
	{
		execl(argv[1], argv[0], "hello world", NULL);

	}

	return 0;
}

//g++ -o lab_3_1 lab_3_1.cpp lab_3_func.cpp
//
//./lab_3_1 "\?"
//
//./lab_3_1 "launch"
