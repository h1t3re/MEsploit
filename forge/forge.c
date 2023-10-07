#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include ".../lib/mem.h"

int *forge_Ethernet_II()
{
	int *Ethernet_II;
	
	return Ethernet_II;
}

int *forge(char *packet_protocol)
{
	int *packet;
	if(strcmp(packet_protocol, "ETHERNET II")==0)
	{
		packet = forge_Ethernet_II();
	}

	return packet;
}
