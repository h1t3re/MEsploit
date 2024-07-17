#include <stdlib.h>
#include <stdio.h>
#include "include/stdlib.h"
#include "include/get_network_configuration.h"
#include "include/forge_arp_packet.h"

int main()
{
	network_configuration **net_config = get_network_configuration();
	network_configuration *interface;
	char *interface_number;
	char *ip_num;
	char *ip;
	char *ip0;
	char *number = (char *)malloc(2*sizeof(char));
	char *machine_number;
	char *ip_number;
	int int_number = 0;;
	int num = 0;;
	int i = 0;
	print_network_configuration(net_config);
	printf("Choose interface number:\n");
	interface_number = read_io();
	int_number = atoi(interface_number);
	interface = net_config[int_number-1];
	print_network_interface(interface);
	while(net_config[int_number-1]->ip_addr[i] != '\0')
	{
		printf("%d: %s\n", i, net_config[int_number-1]->ip_addr[i]);
		i = i +1;
	
	}
	printf("Choose the ip address of the network to scan:\n");
	ip_num = read_io();
	num = atoi(ip_num);
	ip0 = strsplit(strdup(net_config[int_number-1]->ip_addr[num]), strdup(".\0"));
	ip = strconcatenate(strdup(ip0[0]), strdup(".\0"));
	printf("%s%s\n", ip0[0], ip0[1]);
	ip = strconcatenate(strdup(ip0[2]), strdup(".\0"));
	ip = strconcatenate(strdup(ip0[4]), strdup(".\0"));
	for(int i = 0; i < 255; i++)
	{
		snprintf(number, 2*sizeof(char), "%d\0", i);
		ip = strconcatenate(ip, strdup(number));
		printf("Scanning ip address: %s\n", ip);
		forge_arp_packet(strdup("ff:ff:ff:ff:ff:ff\0"), strdup("ff:ff:ff:ff:ff:ff\0"), strdup(net_config[int_number-1]->ip_addr[num]), strdup(ip));
	}
	return 0;
}
