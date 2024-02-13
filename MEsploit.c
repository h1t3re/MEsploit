#include <stdlib.h>
#include <stdio.h>
#include "include/stdlib.h"
#include "include/get_network_configuration.h"
//#include "include/forge_arp_packet.h"

int main()
{
	network_configuration **net_config = get_network_configuration();
	network_configuration *interface;
	char *interface_number;
	int int_number;
	print_network_configuration(net_config);
	printf("Choose interface number:\n");
	interface_number = read_io();
	int_number = atoi(interface_number);
	interface = net_config[int_number-1];
	print_network_interface(interface);
	return 0;
}
