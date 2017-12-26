#include "lab_1.h"

//#include <string.h>
//#include <string>
#include <fstream>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


using namespace std;

#define LINE_BUFSIZE 128

int main()
{

	setlocale(LC_ALL, "Russian");

	char loop;
	string disk_name;
	int count;
	
	printf("Нажмите любую клавишу\n");

	while ((loop = cin.get()) != 27)
	{
		printf("\nВыберите действие:");
		printf("\n1 - Список доступных устройств-накопителей в системе");
		printf("\n2 - параметры устройства");
		printf("\n3 - удаление съёмного утсройства");
		printf("\nctrl+c - выход\n");
		
		cin >> count;
		switch (count)
		{
			case 1: list_storage_dev(); break;
			case 2: cin >> disk_name; get_info(disk_name); break;
			case 3: cin >> disk_name; unplug_dev(disk_name); break;
			dafault: break;
		}
		
	}	
	//printf("%d\n", i);
	return 0;
}


void list_storage_dev()
{
	char line[LINE_BUFSIZE];
	int counter = 0;
	FILE *file;

	printf("\n\n==============================================\n");

	file = popen("./list.sh", "r");
	while (fgets(line, LINE_BUFSIZE, file) != NULL)
	{
		if (counter > 0)
			printf("%d  |  %s", counter, line);
		++counter;
	}

	printf("===============================================\n\n");

	pclose(file);

}



void get_info(string disk_name)
{
	string command  = "parted " + disk_name + " print";

	ofstream f("./get_info.sh");
	f << command;
	f.close();

	char line[LINE_BUFSIZE];
	FILE *file;
	int counter = 0;

	printf("\n\n==============================================\n");

	file = popen("./get_info.sh", "r");
	while (fgets(line, LINE_BUFSIZE, file) != NULL)
	{
		printf("%s", line);
		++counter;
	}

	printf("===============================================\n\n");

	pclose(file);
		

}

void unplug_dev(string disk_name)
{
	if (disk_name != "/dev/sda")
	{

		string command  = "eject " + disk_name + "\n" + "udisksctl power-off -b " + disk_name;
	
		ofstream f("./unplug_dev.sh");
		f << command;
		f.close();
	
		char line[LINE_BUFSIZE];
		FILE *file;
		int counter = 0;
		
		file = popen("./unplug_dev.sh", "r");
		while (fgets(line, LINE_BUFSIZE, file) != NULL)
		{
			printf("%s", line);
			++counter;
		}
		pclose(file);
		
	}
	
	
}






