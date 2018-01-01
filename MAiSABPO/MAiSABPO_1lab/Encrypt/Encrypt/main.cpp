#include <sstream>
#include <iostream>
#include <fstream>
#include <locale.h>
#include <cstring>
#include <vector>
using namespace std;

void Encrypt(char *par1, char *par2, char *par3)
{
	register int t=0, i = 0, j = 0, k = 0;
	char *key = par3;
	size_t size = std::strlen(key);
	printf("Ключ: %s, длина ключа: %d.\n\n", key, size);
	ifstream in(par1, ios::in | ios::binary);
	if (!in) 
	{
		cout << "Cannot open file.\n";
		system("PAUSE");
		//return 1;
	}
	vector<char> contents(istreambuf_iterator<char>(in), (istreambuf_iterator<char>()));
	for(k; k < contents.size() - 1; k++)
	{
		if(contents[k] == '\r')
		{
			if(contents[k+1] == '\n')
			{
				contents.erase(contents.begin() + k);
				vector<char>(contents).swap(contents);
			}
		}
	}
	in.close();
	printf("Текст исходного сообщения:\n'");
	for (i = 0; i < contents.size(); i++)
	{
		cout << contents[i];
	}
	printf("'\n\nИтоговый шифр Виженера:\n'");
	ofstream out(par2,ios::binary|ios::out); //Открываем файл в двоичном режиме для записи

	/*Кодируем полученную последовательность*/
	for (j = 0; j < contents.size(); j++)
	{
		for(t = 0; t < size; t++)
		{
			if (j < contents.size())
			{
				int summa = (int)contents[j] + (int)key[t];
				contents[j] = (char)(summa % 256);
				cout << contents[j];
				out.write((char*)&contents[j],sizeof contents[j]);
				j++;
			}
		}
		j--;
	}
	out.close();
	printf("'\n");
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc!=4) 
	{
		cout<< "Наберите три параметра: исходный файл, выходной файл и ключ!\n"<<endl;
		system("PAUSE");
		//return 1;
	}
	else
	{
		Encrypt(argv[1],argv[2],argv[3]);
		system("PAUSE");
	}
	return 0;
}