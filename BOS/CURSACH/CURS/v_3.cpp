#include "v_3.h"
#include <iostream>
#include <string>
using namespace std;

int HZ = 100;
string SOCKET_TCP = "/proc/net/tcp";
string SOCKET_UDP4 = "/proc/net/udp";
string SOCKET_RAW4 = "/proc/net/raw";
string SOCKET_UNIX = "/proc/net/unix";

int main(int argc, char* argv[])
{
	string IP_FLAG;
	string SOCKET = "";
	
	
	if (string(argv[1]) == "t")
		SOCKET = SOCKET + "/proc/net/tcp";
	else if (string(argv[1]) == "u")
		SOCKET = SOCKET + "/proc/net/udp";
	else if (string(argv[1]) == "r")
		SOCKET = SOCKET + "/proc/net/raw";
	else if (string(argv[1]) == "x")
	{
		SOCKET = SOCKET + "/proc/net/unix";
		IP_FLAG ="unix";
	}

	if (string(argv[1]) != "x")
	{

		if (string(argv[2]) == "4")
		{
			IP_FLAG = "IPv4";
		}	
		else if (string(argv[2]) == "6")
		{	
			SOCKET = SOCKET + "6"; 
			IP_FLAG = "IPv6"; 
		}
	}
	
	open_file(SOCKET, IP_FLAG);
	return 0;

}
