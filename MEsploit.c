#include <stdlib.h>
#include <stdio.h>
#include "include/stdlib.h"
#include "include/get_network_conf.h"

int main()
{
	network_config **net_conf = get_network_conf();
	network_config *interface;
	char *interface_number;
	int int_number;
	print_network_config(net_conf);
	printf("Choose interface number:\n");
	interface_number = read_io();
	int_number = atoi(interface_number);
	interface = net_conf[int_number-1];
	print_network_interface(interface);
	return 0;
}
