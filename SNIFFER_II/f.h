#ifndef F_H_
#define F_H_
#include <vector>
#include <string>
using namespace std;


int start_ss();
void ProcessPacket(unsigned char*, int);
void print_tcp_packet(unsigned char*, int);
void print_udp_packet(unsigned char*, int);
string get_ip_header(unsigned char*, int);
vector <string> split(string str);

#endif
