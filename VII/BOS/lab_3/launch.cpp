#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");

	cout << "ЗАПУСКАЮЩАЯ ПРОГРАММА:" << argv[0] << endl;
	cout << "АРГУМЕНТЫ:" << endl;
	for (int i = 1; i < argc; i++)
	{
		cout << "argv[" << i << "] = " << argv[i] << endl;
	}

	return 0;
}

//g++ launch launch.cpp

