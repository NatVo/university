//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "lab_2.h"
#include <stdio.h>
#include <fstream>

#define LINE_BUFSIZE 128

int CountWords(char *str)
{
	int counter = 0;

	char *pch = strtok(str, " ,.-");

	while (pch != NULL)                        
	{
		counter++;
		pch = strtok(NULL, " ,.-");
	}
	
	return counter;
}

int get_number_of_letters()
{
	char line[LINE_BUFSIZE];
	int counter = 0;
	FILE *file;

	file = popen("./convert.sh", "r");
	while (fgets(line, LINE_BUFSIZE, file) != NULL)
	{
		cout << "";
	}

	pclose(file);

	int n_simv = 0;
	string tfile_line;

	ifstream tfile; tfile.open("lab_2_tmp.txt");
	while (!tfile.eof())
	{	
		getline(tfile, tfile_line);
		n_simv = n_simv + tfile_line.length();
	}
                                           
	tfile.close();

	return n_simv;
}
