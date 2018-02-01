#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
string SOKET_TCP4 = "/proc/net/tcp"; 
string SOKET_TCP6 = "/proc/net/tcp6";
string SOKET_UDP4 = "/proc/net/udp";
string SOKET_UDP6 = "/proc/net/udp6";
string SOKET_RAW4 = "/proc/net/raw";
string SOKET_RAW6 = "/proc/net/raw6";
string SOKET_UNIX = "/proc/net/unix";

void open_file(string file_path, string IP_FLAG);
void parse_string(string file_line, string IP_FLAG);
void print_output_header();
int hex_to_dec(string str);

string hex_ip_to_dec(string ip_addr);
string int_to_str(int number);

string find_correct_proc(string pid, string socket);
string first_line_in_status_file(string line);
string return_status(int status);

vector<string> split_string(string str);
vector<string> get_pids();

int main()
{

	setlocale(LC_ALL, "Russian");
	
	cout << "\nTCP IPv4\n" << endl;
	open_file(SOKET_TCP4, "IPv4");
	cout << "\nUDP IPv4\n" << endl;
	open_file(SOKET_UDP4, "IPv4");
	cout << "\nRAW IPv4\n" << endl;
	open_file(SOKET_RAW4, "IPv4");
	

	cout << "\nTCP IPv6\n" << endl;
	open_file(SOKET_TCP6, "IPv6");
	cout << "\nUDP IPv6\n" << endl;
	open_file(SOKET_UDP6, "IPv6");
	cout << "\nRAW IPv6\n" << endl;
	open_file(SOKET_RAW6, "IPv6");
	
}

void open_file(string file_path, string IP_FLAG)
{

	string file_line;
	bool FLAG = false;

	ifstream goal_file (file_path.c_str());
	print_output_header();

	if (goal_file.is_open())
	{
		while (getline (goal_file, file_line))
		{	
			
			if (FLAG)
			{
			
				replace(file_line.begin(), file_line.end(), ':', ' ');
				parse_string(file_line, IP_FLAG);
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
	string pid = "";
	string proc = "";

	vector<string> pids = get_pids();
			
	int i = 0;
	while (i < pids.size())
	{
		pid = pids[i];
		proc = 	find_correct_proc(pids[i], "[" + tokens[13] + "]"); 
		if (proc != "")
			break;
		proc = "";
		pid = "";
		i++;
	}

	if (FLAG == "IPv4")
	{
	cout << setw(5) << tokens[0] <<
		setw(25) << local_addr <<
		setw(28) << peer_addr << 
		setw(30) << status <<
		setw(31) << pid << 
		setw(32) << proc << endl;
	}
	else
	{

	cout << setw(5) << tokens[0] <<
		setw(54) << local_addr <<
		setw(35) << peer_addr <<
		setw(20) << status <<
		setw(20) << pid << 
		setw(30) << proc << endl;
	}
}

void print_output_header()
{
	cout << setw(5) << "№" <<
		setw(38) << "Локальный адрес" <<
		setw(38) << "Peer адрес" << 
		setw(40) << "Статус" <<
		setw(40) << "ID процесса" << 
		setw(40) << "Процесс" << endl;

	cout << endl;
	cout << "-------------------------------------------------------------------------------";
       	cout << "-------------------------------------------------------------------------------";
	cout << endl;                                                                             
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


string find_correct_proc(string pid, string socket)
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
