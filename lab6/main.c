#include "rawsocsniffer.h"
//#include <linux/if_ether.h>
#include <arpa/inet.h>
#include <iostream>
#include<cstring>
#include<unistd.h>
#include <cstdlib>
using namespace std;
int main(int argc, char ** argv)
{
    // rawsocsniffer sniffer(htons(ETH_P_ALL));
    rawsocsniffer sniffer(htons(0x0003));
    char ch;
    filter myfilter;
    memset(&myfilter,0,sizeof(myfilter));
	// string sipstr,dipstr;
	// cin>>sipstr>>dipstr;
	// const char*sip=sipstr.data();
	// const char*dip=dipstr.data();
	// myfilter.sip=inet_addr(sip);
	// myfilter.dip=inet_addr(dip);
	// bool a,t,u,i;
	// cin>>a>>t>>u>>i;
	// if(a)
	// {
	// 	sniffer.setbit((myfilter.protocol),1);
	// }
	// if(t)
	// {
	// 	sniffer.setbit((myfilter.protocol),2);
	// }
	// if(u)
	// {
	// 	sniffer.setbit((myfilter.protocol),3);
	// }
	// if(i)
	// {
	// 	sniffer.setbit((myfilter.protocol),4);
	// }

    while((ch=getopt(argc, argv,"s:d:atui"))!=-1)
    {
	switch (ch)
	{
	    case 's':
		myfilter.sip=inet_addr(optarg);
		break;
	    case 'd':
		myfilter.dip=inet_addr(optarg);
		break;
	    case 'a':
		sniffer.setbit((myfilter.protocol),1);
		break;
	    case 't':
		sniffer.setbit((myfilter.protocol),2);
		break;
	    case 'u':
		sniffer.setbit((myfilter.protocol),3);
		break;
	    case 'i':
		sniffer.setbit((myfilter.protocol),4);
		break;
	    default:
		break;
	}
    }
    cout<<"create sniffer succeed."<<endl;
    
    //set sniffer filter;
    sniffer.setfilter(myfilter);
    
    //sniffer initialize
    if(!sniffer.init())
    {
	cout<<"sniffer initialize error!"<<endl;
	exit(-1);
    }

    //start to capture packets;
    sniffer.sniffer();
}
