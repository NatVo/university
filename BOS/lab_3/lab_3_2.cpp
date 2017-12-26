#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

using namespace std;

#define LINE_BUFSIZE 128

void launch(string f);

void launch(string f)
{
	char line[LINE_BUFSIZE];
	int counter = 0;
	FILE *file;

	file = popen(f.c_str(), "r");
	while (fgets(line, LINE_BUFSIZE, file) != NULL)
	{
		printf("%s", line);
		++counter;
	}

	pclose(file);

}

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
		string f = argv[1];
		launch(f);
		
	}
	return 0;
}

//g++ -o lab_3_2 lab_3_2.cpp
//
//./lab_3_2 "\?"
//
//./lab_3_2 "./launch.sh"
//
//./lab_3_2 "./firefox.sh"
