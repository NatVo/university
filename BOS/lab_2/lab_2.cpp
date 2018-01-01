//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <locale>
//#include <string.h>
#include <stdio.h>

#include "lab_2.h"

#define LINE_BUFSIZE 128

//BEFORE USING SAVE TXT IN cp1251 ENCODE!!! EXCEPT WILL BE GETTIN WRONG NUMBER OF LETTERS

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc == 2 && strcmp(argv[1], "\\?") == 0)
	{
		cout << "СПРАВКА:\n\n";
		cout << "Обработка стандартных потоков ввода-вывода\n\n";
		cout << "Разработать программу подсчета печатных символов, слов и строк, проходящих\n";
		cout << "ч/з стандартные потоки ввода-вывода. Учитывать не только символы латинского алфавита\n";
		cout << "но и символы национальных алфавитов.\n\n";
		cout << "Автор: Воробьева Н. О. БИс-41\n\n";
	}
	
	else
	{
		int n_str = 0;
		int n_simv = 0;
		int n_sl = 0;

		ifstream file; file.open(argv[1]);
	
		if (file && argc == 2)
		{
				
			string line;
			char *str;

			while (!file.eof())
			{
				int l_count = 0;
				getline(file, line);
				str = new char[line.length() + 1];
				strcpy(str, line.c_str());
				
				n_sl = n_sl + CountWords(str);
				n_str++;
			}
			n_str--;
			n_simv = get_number_of_letters();
			
			file.close();

			cout << "\n===========================================" << endl;
			cout << "\nКоличество введеных символов: " << n_simv << "\n";
			cout << "Количество введеных слов: " << n_sl << "\n";
			cout << "Количество введеных строк: " << n_str << "\n\n";
			cout << "===========================================\n" << endl;

		
		}

		else
		{
			for (int i = 1; i < argc; i++)
			{
			n_str++;
			n_simv = n_simv + strlen(argv[i]);
			n_sl = n_sl + CountWords(argv[i]);
			}

			cout << "\n===========================================" << endl;
			cout << "Количество введеных символов: " << n_simv << "\n";
			cout << "Количество введеных слов: " << n_sl << "\n";
			cout << "Количество введеных строк: " << n_str << "\n";
			cout << "===========================================\n" << endl;		
		}
		
	}

	return 0;


}
