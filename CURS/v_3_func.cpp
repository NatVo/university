#include "v_3.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
//#include <vector>
#include <iomanip>
#include <algorithm>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


void open_file(string file_path, string IP_FLAG)
{

	string file_line;
	bool FLAG = false;

	ifstream goal_file (file_path.c_str());

	if (IP_FLAG == "unix")
		print_unix_output_header();
	else
		print_output_header(IP_FLAG);


	if (goal_file.is_open())
	{
		while (getline (goal_file, file_line))
		{	
			
			if (FLAG)
			{
		
				if (IP_FLAG == "unix")
				{
					parse_unix_string(file_line);
				}
				else
				{
					replace(file_line.begin(), file_line.end(), ':', ' ');
					parse_string(file_line, IP_FLAG);
				}	
			}	
			FLAG = true;
				
				
		}
	}
	goal_file.close();	

}


void parse_string(string file_line, string FLAG)
{
	vector<string> tokens = split_string(file_line);
	string local_port = int_to_str(hex_to_dec(tokens[2]));
	string peer_port = int_to_str(hex_to_dec(tokens[4]));

	string local_addr = hex_ip_to_dec(tokens[1]) + ":" + local_port;
	string peer_addr = hex_ip_to_dec(tokens[3]) + ":" + peer_port;
	string status = return_status(hex_to_dec(tokens[5]));
	string timeout = int_to_str(hex_to_dec(tokens[9]) / 100);
	string pid = "";
	string proc = "";

	vector<string> pids = get_pids();
			
	int i = 0;
	while (i < pids.size())
	{
		pid = pids[i];
		proc = 	find_correct_process(pids[i], "[" + tokens[13] + "]"); 
		if (proc != "")
			break;
		pid = "";
		proc = "";
		i++;
	}

	if (FLAG == "IPv4")
	{
		printf("%5s | %20s | %20s | %10s | %8s | %10s | %8s |\n", 
				tokens[0].c_str(),
				local_addr.c_str(),
				peer_addr.c_str(),
				status.c_str(),
				pid.c_str(),
				proc.c_str(),
				timeout.c_str());
		for (int i = 0; i < 100; i++)
			printf("-");
		printf("\n");
	}

	else
	{
		printf("%5s | %52s | %52s | %10s | %8s | %10s | %8s |\n", 	
        			tokens[0].c_str(),
        			local_addr.c_str(),
        			peer_addr.c_str(),
        			status.c_str(),
        			pid.c_str(),
        			proc.c_str(),
				timeout.c_str());
        	for (int i = 0; i < 164; i++)
        		printf("-");
        	printf("\n");

	}

}

void parse_unix_string(string file_line)
{
	
	file_line = file_line + " *";
	
	vector<string> tokens = split_string(file_line);
	
	string status = return_status(hex_to_dec(tokens[5]));
	string addres = tokens[7] + ":" + tokens[6];
	string pid = "";
	string proc = "";
	
	vector<string> pids = get_pids();
			
	int i = 0;
	
	while (i < pids.size())
	{
		pid = pids[i];
		proc = 	find_correct_process(pids[i], "[" + tokens[6] + "]"); 
		if (proc != "")
			break;
		i++;
	}

	printf("%10s | %60s | %10s | %20s |\n", 
        		status.c_str(),
        		addres.c_str(),
        		pid.c_str(),
        		proc.c_str());
        for (int i = 0; i < 110; i++)
        	printf("-");
        printf("\n");
}

void print_output_header(string FLAG)
{

	if (FLAG == "IPv4")
	{
		printf("%5s | %20s | %20s | %10s | %8s | %10s | %8s |\n", 
			"",
			"local_addr",
			"peer_addr",
			"status",
			"pid",
			"process",
			"timeout");
		for (int i = 0; i < 100; i++)
			printf("-");
		printf("\n");
	}

	else
	{
		printf("%5s | %52s | %52s | %10s | %8s | %10s | %8s |\n", 	
 			"",                
 			"local_addr",       
 			"peer_addr",        
 			"status",           
 			"pid",              
 			"process",          
 			"timeout");         
        	for (int i = 0; i < 164; i++)
        		printf("-");
        	printf("\n");

	}

}

void print_unix_output_header()
{

	printf("%10s | %60s | %10s | %20s |\n", 
        		"status",
        		"addres",
        		"pid",
        		"process");
        for (int i = 0; i < 110; i++)
        	printf("-");
        printf("\n");

}

int hex_to_dec(string str)
{
	return strtoull(str.c_str(), NULL, 16);
}


string hex_ip_to_dec(string ip_addr)
{
	string output_str = "";
		
	for (int i = ip_addr.size() - 2; i >= 0; i = i - 2)
	{
		string tmp = ip_addr.substr(i, 2);
		int x = hex_to_dec(tmp.c_str());
		
		string str_tmp = int_to_str(x);
		
		if (i != 0)	
			output_str = output_str + str_tmp + ".";
		else
			output_str = output_str + str_tmp;
	}

	return output_str;
}

string int_to_str(int number)
{
	stringstream ss;
	ss << number;
	return ss.str();
}


string find_correct_process(string pid, string socket)
{
	string TOTAL_PATH = "/proc/" + pid + "/fd";
	string proc = "";
	DIR *dir = opendir(TOTAL_PATH.c_str());
	FILE *f;
	char line[1035];
	
	if (dir)
	{
		string LS_TOTAL_PATH = "/bin/ls -l " + TOTAL_PATH;
		f = popen(LS_TOTAL_PATH.c_str(), "r");
		
		while (fgets(line, sizeof(line) - 1, f) != NULL) 
		{
			if (strstr(line, socket.c_str()))
			{
				string STATUS_FILE_PATH = "/proc/" + pid + "/status";
				string status_1_line = first_line_in_status_file(STATUS_FILE_PATH);
				vector<string> proc_info = split_string(status_1_line);	
				proc = proc_info[1];
					
			}
		}
		pclose(f);
		
	}
	closedir(dir);
	return proc;

}


string first_line_in_status_file(string path)
{
	string line;
	ifstream get_file(path.c_str());
	if (get_file.is_open())
		getline(get_file, line);
	get_file.close();

	return line;	

}


string return_status(int status)
{
	string STATUS;
	switch (status)
	{
		case 1: STATUS = "ESTAB"; break;
		case 2: STATUS = "SYN_SENT"; break;
		case 3: STATUS = "SYN_RECV"; break;
		case 4: STATUS = "FIN_WAIT1"; break;
		case 5: STATUS = "FIN_WAIT2"; break;
		case 6: STATUS = "TIME_WAIT"; break;
		case 7: STATUS = "CLOSE"; break;
        	case 8: STATUS = "CLOSE_WAIT"; break;
		case 9: STATUS = "LAST_ACK"; break;    	
        	case 10: STATUS = "LISTEN"; break;
        	case 11: STATUS = "CLOSING"; break;
		default: STATUS = ""; break;
	}	
	return STATUS;
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

vector<string> get_pids()
{
	DIR *dir = opendir("/proc");
	struct dirent *entry = readdir(dir);
	vector<string> pids;
	while ( (entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_DIR && atoi(entry->d_name))
			pids.push_back(entry->d_name);
	}
	closedir(dir);

	return pids;
}
