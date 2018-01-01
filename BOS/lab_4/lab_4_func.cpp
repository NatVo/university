#include <stdio.h>
#include <fstream>
#include <sstream>

#include "lab_4.h"
#define LINE_BUFSIZE 128

int list_drivers() 
{

    	ifstream f("/proc/modules");
	string line;
	string Live = "Live 0x0000000000000000";
    	vector<string> tokens;
	//printf("%43s | %25s\n", "ДРАЙВЕР", "НАЗВАНИЕ");
	printf("\n-----------------------------------------------------------------------------------------------\n"); 

    	while (getline(f, line)) 
	{
		line = line.substr(0, line.size() - Live.size());
		tokens = split_string(line);
        	printf("%20s | %10s | %s15 | %s25\n", tokens[0].c_str(), tokens[1].c_str(), tokens[2].c_str(), tokens[3].c_str());
		printf("-----------------------------------------------------------------------------------------------\n");
    	}
    	
    	return 0;

}


void list_service(bool FLAG, string one_service)
{
	cout << one_service << endl;
	char line[LINE_BUFSIZE];
	string str_line(line);
	int counter = 0;
	int i = 0;
	FILE *file;
	vector<string> tokens;

	printf("\n\n=====================================================================================================\n");

	file = popen("./service.sh", "r");
	while (fgets(line, LINE_BUFSIZE, file) != NULL)
	{
		//istringstream iss(line);
		if (counter > 0)
			i = 0;
			str_line = line;
			if (str_line.find("service") != string::npos)
			{
				tokens = split_string(str_line);
				if (!FLAG)
				{ 
					printf("%55s | %20s | %20s\n", tokens[0].c_str(), tokens[3].c_str(), tokens[4].c_str());
					printf("-----------------------------------------------------------------------------------------------------\n");
				}
				else
				{
					if (tokens[4].find(one_service) != string::npos)
						printf("%55s | %20s | %20s\n", tokens[0].c_str(), tokens[3].c_str(), tokens[4].c_str());
						
				}
				


			}	
			
		++counter;
	}

	printf("=====================================================================================================\n\n");

	pclose(file);

}

vector<string> split_string(string str)
{
	string buf;

	stringstream ss(str);
	vector<string> tokens; 

	while (ss >> buf)
		tokens.push_back(buf);	

	return tokens;
}

