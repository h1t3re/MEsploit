#include "../../include/stdlib.h"
#include "get_network_conf.h"
#include <stdlib.h>
#include <stdio.h>

int print_network_interface(network_config *net_conf)
{
	int i = 0;
	printf("%d:", net_conf->number);
	printf("%s: ", net_conf->name);
	printf("%s\n", net_conf->mac_addr);
	while(net_conf->ip_addr[i] != '\0')
	{
		printf("%s\n", net_conf->ip_addr[i]);
		i = i +1;
	}
	return 0;
}


int print_network_config(network_config **net_conf)
{
	int i = 0;
	while(net_conf[i] != '\0')
	{
		print_network_interface(net_conf[i]);
		i = i +1;
		printf("\n\n");
	}
	return 0;
}

int free_network_config_struct(network_config **net_conf)
{
	int i = 0;
	int j = 0;
	while(net_conf[i] != '\0')
	{
		free(net_conf[i]->name);
		free(net_conf[i]->mac_addr);
		while(net_conf[i]->ip_addr[j] != '\0')
		{
			free(net_conf[i]->ip_addr[j]);
			j = j +1;
		}
		j = 0;
		i = i +1;
	}
	return 0;
}

network_config **get_network_conf()
{
	system("echo \"$(ip a)\" > net_conf.txt\0");
	char *file_name = strdup("./net_conf.txt\0");
	char *mode = strdup("r\0");
	network_config **net_conf = (network_config **)malloc(sizeof(struct net_config *));
	char *data;
	char *key;
	char *end_of_data;
	char *n = (char *)malloc(2*sizeof(char));
	char *t = strdup(": \0");
	char **c0;
	char **c1;
	char **m;
	char *p;
	char *c;
	char *interface_name;
	int i = 0;
	int a = 0;
	char *buffer = read_file(file_name, mode);
	system("echo \"$(ls -A /sys/class/net | wc -l)\" > number_of_interfaces.txt\0");
	file_name = strdup("./number_of_interfaces.txt\0");	
	char *number_of_inter = read_file(file_name, mode);
	int number_of_interfaces = atoi(number_of_inter);
	while((i+1) <= number_of_interfaces)
	{
		net_conf[i] = (network_config *)malloc(sizeof(struct net_config));
		net_conf[i]->number = i+1;
		
		snprintf(n, 2*sizeof(char), "%d\0", (i+1));
		key = strconcatenate(n, t);
		snprintf(n, 2*sizeof(char), "%d\0", (i+2));
		end_of_data = strconcatenate(n, t); 
		data = get_data_by_key_until_end(buffer, key, end_of_data);
		
		key = strdup("link\0");
		c0 = get_data_by_key(data, key, -1);
		p = strdup(" \0");
		m = strsplit(strdup(c0[0]), p);
		net_conf[i]->mac_addr = strdup(m[1]);
		free(key);
		free(m);
		free(c0);
	
		key = strdup(": \0");
		c0 = get_data_by_key(data, key, -1);
		m = strsplit(strdup(c0[0]), p);
		c = strdup(m[1]);
		interface_name = strstrip(c, ':');
		net_conf[i]->name = strdup(interface_name);
		free(key);
		free(m);
		
		key = strdup("inet\0");
		c1 = get_data_by_key(data, key, -1);
		net_conf[i]->ip_addr = (char **)malloc(sizeof(char *));
		while(c1[a] != '\0')
		{
			m = strsplit(c1[a], p);
			net_conf[i]->ip_addr[a] = strdup(m[1]); 
			a = a +1;
			net_conf[i]->ip_addr = (char **)realloc(net_conf[i]->ip_addr, (a+1)*sizeof(char *));
		}
		net_conf[i]->ip_addr[a] = '\0';
		a = 0;
		free(c0);
		free(c1);
		free(data);
		free(m);
		free(end_of_data);
		i = i +1;
		net_conf = (network_config **)realloc(net_conf, (i+1)*sizeof(struct net_config *));
	}
	net_conf[i] = '\0';
	free(buffer);
	free(file_name);
	free(mode);
	free(n);
	free(t);
	free(p);
	free(interface_name);
	free(number_of_inter);	
	return net_conf;
}
