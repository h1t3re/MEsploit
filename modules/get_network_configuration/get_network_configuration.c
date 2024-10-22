#include "../../include/stdlib.h"
#include <stdlib.h>
#include <stdio.h>
#include "get_network_configuration.h"


int print_network_interface(network_configuration *network_config)
{
	int i = 0;
	printf("%d:", network_config->number);
	printf("%s: ", network_config->name);
	printf("%s\n", network_config->mac_addr);
	while(network_config->ip_addr[i] != '\0')
	{
		printf("%s\n", network_config->ip_addr[i]);
		i = i +1;
	}
	return 0;
}

int print_network_configuration(network_configuration **network_config)
{
	int i = 0;
	while(network_config[i] != '\0')
	{
		print_network_interface(network_config[i]);
		i = i +1;
		printf("\n\n");
	}
	return 0;
}

int free_network_configuration_struct(network_configuration **network_config)
{
	int i = 0;
	int j = 0;
	while(network_config[i] != '\0')
	{
		free(network_config[i]->name);
		free(network_config[i]->mac_addr);
		while(network_config[i]->ip_addr[j] != '\0')
		{
			free(network_config[i]->ip_addr[j]);
			j = j +1;
		}
		j = 0;
		i = i +1;
	}
	free(network_config);
	return 0;
}

network_configuration **get_network_configuration()
{
	system("echo \"$(ip a)\" > net_conf.txt\0");
	char *file_name = strdup("./net_conf.txt\0");
	char *mode = strdup("r\0");
	network_configuration **net_config = (network_configuration **)malloc(sizeof(struct network_config *));
	char *data;
	char *key;
	char *end_of_data;
	char *n0 = (char *)malloc(2*sizeof(char));
	char *n1 = (char *)malloc(2*sizeof(char));
	char *t = strdup(": \0");
	char **c0;
	char **c1;
	char **m;
	char *p;
	char *c;
	char *interface_name;
	int i = 0;
	int a = 0;
	char *buffer = read_file_v1(file_name);
	system("echo \"$(ls -A /sys/class/net | wc -l)\" > number_of_interfaces.txt\0");
	file_name = strdup("./number_of_interfaces.txt\0");	
	char *number_of_inter = read_file(file_name);
	int number_of_interfaces = atoi(number_of_inter);
	while((i+1) <= number_of_interfaces)
	{
		net_config[i] = (network_configuration *)malloc(sizeof(struct network_config));
		net_config[i]->number = i+1;
		
		snprintf(n0, 2*sizeof(char), "%d\0", (i+1));
		key = strconcatenate(n0, t);
		snprintf(n1, 2*sizeof(char), "%d\0", (i+2));
		end_of_data = strconcatenate(n1, t); 
		data = get_data_by_key_until_end(buffer, key, end_of_data);
		
		key = strdup("link\0");
		c0 = get_data_by_key(data, key, -1);
		p = strdup(" \0");
		m = strsplit(strdup(c0[0]), p);
		net_config[i]->mac_addr = strdup(m[1]);
		free(key);
		free(m);
		free(c0);
	
		key = strdup(": \0");
		c0 = get_data_by_key(data, key, -1);
		m = strsplit(strdup(c0[0]), p);
		c = strdup(m[1]);
		interface_name = strstrip(c, strdup(":\0"));
		net_config[i]->name = strdup(interface_name);
		free(key);
		
		key = strdup("inet\0");
		c1 = get_data_by_key(data, key, -1);
		net_config[i]->ip_addr = (char **)malloc(sizeof(char *));
		while(c1[a] != '\0')
		{
			m = strsplit(c1[a], p);
			net_config[i]->ip_addr[a] = strdup(m[1]); 
			a = a +1;
			net_config[i]->ip_addr = (char **)realloc(net_config[i]->ip_addr, (a+1)*sizeof(char *));
		}
		net_config[i]->ip_addr[a] = '\0';
		a = 0;
		free(c0);
		free(c1);
		free(data);
		free(m);
		free(end_of_data);
		i = i +1;
		net_config = (network_configuration **)realloc(net_config, (i+1)*sizeof(struct network_config *));
	}
	net_config[i] = '\0';
	free(buffer);
	free(file_name);
	free(mode);
	//free(n);
	free(t);
	//free(p);
	//free(interface_name);
	free(number_of_inter);
	return net_config;
}
