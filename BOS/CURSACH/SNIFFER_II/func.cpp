#include "f.h"

#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>    //malloc
#include <string.h>    //strlen
#include <string>
#include <vector>
#include <sstream>

#include <netinet/udp.h>   //udp header
#include <netinet/tcp.h>   //tcp header
#include <netinet/ip.h>    //ip header
#include <netinet/if_ether.h>  //ETH_P_ALL
#include <sys/socket.h>
#include <arpa/inet.h>
#include<unistd.h>

using namespace std;

FILE *file;
struct sockaddr_in source,dest;
int tcp=0,udp=0,icmp=0,others=0,igmp=0,total=0;
int i;
int j; 

int start_ss()
{
	file = fopen("log.txt", "w");

	int saddr_size, data_size;
	struct sockaddr saddr;
       	unsigned char *buffer = (unsigned char *) malloc(65536); 
	int sock_raw = socket( AF_PACKET , SOCK_RAW , htons(ETH_P_ALL)) ;
     
    	while(1)
    	{
        	saddr_size = sizeof saddr;
		data_size = recvfrom(sock_raw , buffer , 65536 , 0 , &saddr , (socklen_t*)&saddr_size);
		if(data_size <0 )
        	{
            		printf("Recvfrom error , failed to get packets\n");
            		return 1;
        	}
	        ProcessPacket(buffer , data_size);
    	}

    	close(sock_raw);
    	return 0;
}

void ProcessPacket(unsigned char* buffer, int size)
{
	struct iphdr *iph = (struct iphdr*)(buffer + sizeof(struct ethhdr));
	++total;
    	switch (iph->protocol)
    	{
               	case 6: ++tcp; print_tcp_packet(buffer , size); break;
        	case 17:++udp; print_udp_packet(buffer , size); break;
         	default: ++others; break;
    	}
   
}
 
 
string get_ip_header(unsigned char* Buffer, int Size)
{
	unsigned short iphdrlen;
	struct iphdr *iph = (struct iphdr *)(Buffer  + sizeof(struct ethhdr) );
	iphdrlen =iph->ihl*4;
	
	memset(&source, 0, sizeof(source));
	source.sin_addr.s_addr = iph->saddr;
     
	memset(&dest, 0, sizeof(dest));
	dest.sin_addr.s_addr = iph->daddr;
     	
	string str;
	str = string(inet_ntoa(source.sin_addr));
	str = str + " " + string(inet_ntoa(dest.sin_addr));
	
	printf("%10d %10d  ", ntohs(iph->tot_len), (unsigned int)iph->ttl); 
	fprintf(file, "%10d %10d  ", ntohs(iph->tot_len), (unsigned int)iph->ttl); 
	return str;
}
 
void print_tcp_packet(unsigned char* Buffer, int Size)
{
	unsigned short iphdrlen;
	struct iphdr *iph = (struct iphdr *)( Buffer  + sizeof(struct ethhdr) );
	iphdrlen = iph->ihl*4;
	
	struct tcphdr *tcph=(struct tcphdr*)(Buffer + iphdrlen + sizeof(struct ethhdr));
	int header_size =  sizeof(struct ethhdr) + iphdrlen + tcph->doff*4;
	
	printf( "\nTCP %10s %6s %25s %5s %25s %5s\n", "length", "ttl", "source_ip:", "port", "dest_ip:", "port");  
	printf("----------------------------------------------------------------------------------------------\n");
	fprintf(file, "\n\nTCP %10s %6s %25s %5s %25s %5s\n", "length", "ttl", "source_ip:", "port", "dest_ip:", "port");  

	fprintf(file, "-----------------------------------------------------------------------------------------\n");

	vector<string> str = split(get_ip_header(Buffer,Size));
	
	printf("%25s:%5u %25s:%5u\n", str[0].c_str(), ntohs(tcph->source), str[1].c_str(), ntohs(tcph->dest));	

	fprintf(file, "%25s:%5u %25s:%5u ", str[0].c_str(), ntohs(tcph->source), str[1].c_str(), ntohs(tcph->dest));
}

void print_udp_packet(unsigned char *Buffer , int Size)
{
	unsigned short iphdrlen;
	
	struct iphdr *iph = (struct iphdr *)(Buffer +  sizeof(struct ethhdr));
	iphdrlen = iph->ihl*4;
	
	struct udphdr *udph = (struct udphdr*)(Buffer + iphdrlen  + sizeof(struct ethhdr));
	int header_size =  sizeof(struct ethhdr) + iphdrlen + sizeof udph;

	printf( "\nUDP %10s %6s %25s %5s %25s %5s\n", "length", "ttl", "source_ip:", "port", "dest_ip:", "port");  
	printf("----------------------------------------------------------------------------------------------\n");

	fprintf(file, "\n\nUDP %10s %6s %25s %5s %25s %5s\n", "length", "ttl", "source_ip:", "port", "dest_ip:", "port");  

	fprintf(file, "-----------------------------------------------------------------------------------------\n");

	vector<string> str = split(get_ip_header(Buffer,Size));          

	printf("%25s:%5u %25s:%5u\n", str[0].c_str(), ntohs(udph->source), str[1].c_str(), ntohs(udph->dest));

	fprintf(file, "%25s:%5u %25s:%5u ", str[0].c_str(), ntohs(udph->source), str[1].c_str(), ntohs(udph->dest));
	
}


vector<string> split(string str)
{
	string buf;
	stringstream ss(str);
	vector<string> tmp;
	while (ss >> buf)
		tmp.push_back(buf);

	return tmp;
}


