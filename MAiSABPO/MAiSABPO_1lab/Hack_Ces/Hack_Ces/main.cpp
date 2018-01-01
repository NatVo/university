#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <string>
#include "windows.h"

using namespace std;

int GetNumChar(char a)
{
    for (int i = 0; i < 256; i++) {
        if((char)i==a){
            return i;
        }
    }
}

char GetCharNum(int a)
{
    for (int i = 0; i < 256; i++) {
        if(i==a){
            return (char)i;
        }
    }
}

vector<char> findper(vector<char> x1, vector<char> x2)
{
	vector<char> result;
	for(int i = 0; i < x1.size(); i++)
	{
		for(int j = 0; j < x2.size(); j++)
		{
			if(x1[i] == x2[j])
			{
				result.push_back(x1[i]);
				break;
			}
		}
	}
	return result;
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);  
	SetConsoleOutputCP(1251);
	if (argc > 1)
    {
		bool t = true;
		ifstream  f(argv[1], ios::in | ios::binary);
		vector<char> contents(istreambuf_iterator<char>(f), (istreambuf_iterator<char>()));
		for(int i = 0; i < contents.size() - 1; i++)
		{
			if(contents[i] == '\r')
			{
				if(contents[i + 1] == '\n')
				{
					contents.erase(contents.begin() + i);
					vector<char>(contents).swap(contents);
				}
			}
		}
		f.close();
		vector<char> x1, x2, result;
		string key = "";
		int n = 0, per = 1;
		for(int i = 1; i < contents.size(); i++)
		{
			if(key.size() == per)
				break;
			for(int g = 0; g < 256; g++)
			{
				if(
					((g > 96) && (g < 123)) || 
					((g > 64) && (g < 91)) || 
					((g > 47) && (g < 58)) || 
					((g > 191) && (g < 256)) || 
					g == 32 || g == 46 || 
					g == 33 || g == 63 || 
					g == 44 || g == 45 || 
					g == 10 || g == 13 || 
					g == 58 || g == 59 || 
					g == 171 || g == 187 || 
					g == 150 || g == 151 ||
					g == 133)
				{
					int c_ing = (GetNumChar(contents[n]) + 256 - g) % 256;
					char c_char = GetCharNum(c_ing);
					x1.push_back(c_char);
				}
			}
			for(int j = n + i; j < contents.size(); j += i)
			{
				for(int g = 0; g < 256; g++)
				{
					if(
						((g > 96) && (g < 123)) || 
						((g > 64) && (g < 91)) || 
						((g > 47) && (g < 58)) || 
						((g > 191) && (g < 256)) || 
						g == 32 || g == 46 || 
						g == 33 || g == 63 || 
						g == 44 || g == 45 || 
						g == 10 || g == 13 || 
						g == 58 || g == 59 || 
						g == 171 || g == 187 || 
						g == 150 || g == 151 ||
						g == 133)
					{
						int c_ing = (GetNumChar(contents[j]) + 256 - g) % 256;
						char c_char = GetCharNum(c_ing);
						x2.push_back(c_char);
					}
				}
				result = findper(x1, x2);
				x2.clear();
				if(result.size() == 0)
					break;
				else
					x1 = result;
			}
			if (result.size() == 1)
			{
				if(t)
					per = i;
				t = false;
				key += result[0];
				n++;
				i--;				
			}
			x1.clear();
			result.clear();
		}
		cout << "Key: " << key << endl;
		getch();
    } 
	else
    {
        cout << "Отсутствуют аргументы" << endl;
		getch();
    }
}