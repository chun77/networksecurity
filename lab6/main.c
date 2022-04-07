#include "rawsocsniffer.h"
//#include <linux/if_ether.h>
#include <arpa/inet.h>
#include <iostream>
#include<cstring>
#include<unistd.h>
#include <cstdlib>
using namespace std;
#define ETH_P_ALL 0x0003
int main()
{
    rawsocsniffer sniffer(htons(ETH_P_ALL)); 
	filter myfilter;
    memset(&myfilter,0,sizeof(myfilter));
	string sipstr,dipstr;
	cin>>sipstr>>dipstr;
	const char*sip=sipstr.data();
	const char*dip=dipstr.data();
	myfilter.sip=inet_addr(sip);
	myfilter.dip=inet_addr(dip);
	// myfilter.sip=inet_addr("0.0.0.0");
	// myfilter.dip=inet_addr("192.168.226.130");
	int a,t,u,i;
	cin>>a>>t>>u>>i;
	if(a)
	{
		sniffer.setbit((myfilter.protocol),1);
	}
	if (t)
	{
		sniffer.setbit((myfilter.protocol),2);
	}
	if (u)
	{
		sniffer.setbit((myfilter.protocol),3);
	}
	if (i)
	{
		sniffer.setbit((myfilter.protocol),4);
	}

    sniffer.setfilter(myfilter);
    sniffer.sniffer();
}