#include "../../include/stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_macaddr_to_binary(int *restrict array, const char *restrict mac_addr)
{
	int i = 0;
	int j = 0;
	int c = 0;
	int *t = (int *)malloc(4*sizeof(int));
	while(mac_addr[i] != '\0')
	{
		if(mac_addr[i] != ':')
		{
			convert_hexa_to_binary(t, mac_addr[i], 1);
			while(j < 4)
			{
				array[(c*4)+j] = t[4-j-1];
				j = j +1;
			}
			j = 0;
			c = c +1;
			t = (int *)memset((void *)t, 0, 4*sizeof(int));
		}
		i = i +1;
	}
}

void convert_ipaddr_to_binary(int *restrict array, const char *restrict ip_addr)
{
	int i = 0;
	int j = 0;
	int c = 0;
	int n = 0;
	int *t = (int *)malloc(8*sizeof(int));
	char *number = (char *)malloc(3*sizeof(char));
	while(ip_addr[i] != '\0')
	{
		while((ip_addr[i] != '.') & (ip_addr[i] != '\0'))
		{
			number[n] = ip_addr[i];
			n = n +1;
			i = i +1;
		}	
		number[n] = '\0';
		n = 0;
		convert_integer_to_binary(t, atoi(number), 1, 8);
		while(j < 8)
		{
			array[(c*8)+j] = t[8-j-1];
			j = j +1;	
		}
		j = 0;
		i = i +1;
		c = c +1;
		number = (char *)memset((void *)number , 0, 3*sizeof(char));
		t = (int*)memset((void *)t , 0, 8*sizeof(int));
	}
}

int *forge_arp_packet(const char *restrict snd_macaddr, const char *restrict rcv_macaddr,  const char *restrict snd_ipaddr, const char *restrict rcv_ipaddr)
{	
	int *HT;	//Hardware Type (*)
	int *PT;	//Protocol Type (*)
	int *HAL;	//Hardware Address Length (*)
	int *PAL;	//Protocol Address Length (uses new value 12)
	int *OP;	//Operation Code (uses experimental value OP_EXP1=24)
	int *S_HA;	//Sender Hardware Address (*)
	int *S_L32;	//Sender L32  (* same as Sender IPv4 address for ARP)
	int *S_NID;	//Sender Node Identifier (8 bytes)
	int *T_HA;	//Target Hardware Address (*)
	int *T_L32;	//Target L32  (* same as Target IPv4 address for ARP)
	int *T_NID;	//Target Node Identifier (8 bytes)
	int *sender_macaddr = (int *)malloc((12*4)*sizeof(int));
	int *receiver_macaddr = (int *)malloc((12*4)*sizeof(int));
	int *sender_ipaddr = (int *)malloc((8*4)*sizeof(int)); 
	int *receiver_ipaddr = (int *)malloc((8*4)*sizeof(int)); 
	int *array;
	int type[] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0};
	int hwtype[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	int protocoltype[] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int hwsize[] = {0, 0, 0, 0, 0, 1, 1, 0};	
	int protocolsize[] = {0, 0, 0, 0, 0, 1, 0, 0};	
	int opcode[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	int i = 0;
	convert_macaddr_to_binary(sender_macaddr, snd_macaddr);
	convert_macaddr_to_binary(receiver_macaddr, rcv_macaddr);
	convert_ipaddr_to_binary(sender_ipaddr, snd_ipaddr);
	convert_ipaddr_to_binary(receiver_ipaddr, rcv_ipaddr);
	array = concatenate_int_arrays(sender_macaddr, (12*4), receiver_macaddr, (12*4)); 	
	array = concatenate_int_arrays(array, 2*(12*4), type, 16);
	array = concatenate_int_arrays(array, 2*(12*4)+16, hwtype, 16);
	array = concatenate_int_arrays(array, 2*(12*4)+16+16, protocoltype, 16);
	array = concatenate_int_arrays(array, 2*(12*4)+16+16+16, hwsize, 16);
	array = concatenate_int_arrays(array, 2*(12*4)+16+16+16+16, protocolsize, 16);
	array = concatenate_int_arrays(array, 2*(12*4)+16+16+16+16+16, opcode, 16);
	array = concatenate_int_arrays(array, 2*(12*4)+16+16+16+16+16+16, sender_macaddr, (12*4));
	array = concatenate_int_arrays(array, 2*(12*4)+16+16+16+16+16+16+(12*4), sender_ipaddr, 32);
	array = concatenate_int_arrays(array, 2*(12*4)+16+16+16+16+16+16+(12*4)+32, receiver_macaddr, (12*4));
	array = concatenate_int_arrays(array, 2*(12*4)+16+16+16+16+16+16+(12*4)+32+(12*4), receiver_ipaddr, 32);
	while(i < 2*(12*4)+16+16+8+16+(2*(12*4))+(2*32))
	{
		printf("%d", array[i]);
		i = i +1;
	}
	printf("\n");
	return array;
}
