#ifndef V_3_H_
#define V_3_H_
#include <string>
#include <vector>
using namespace std;

void open_file(string file_path, string IP_FLAG);

void parse_string(string file_line, string IP_FLAG);
void parse_unix_string(string file_line);

void print_output_header(string FLAG);
void print_unix_output_header();

int hex_to_dec(string str);
string hex_ip_to_dec(string ip_addr);
string int_to_str(int number);

string find_correct_process(string pid, string socket);
string first_line_in_status_file(string line);
string return_status(int status);

vector<string> split_string(string str);
vector<string> get_pids();

#endif
