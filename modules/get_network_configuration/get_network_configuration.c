#include "../../include/stdlib.h"
#include "./get_network_configuration.h"
#include <stdlib.h>
#include <stdio.h>

int print_network_interface(network_configuration *net_conf)
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

int print_network_config(network_configuration **net_conf)
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

int free_network_config_struct(network_configuration **net_conf)
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
        free(net_conf);
        return 0;
}

network_configuration **get_network_conf()
{
        system("echo \"$(ip a)\" > net_conf.txt\0");
        char *file_name = strdup("/home/user/MEsploit/modules/get_network_configuration/net_conf.txt\0");
        char *mode = strdup("r\0");
        char *buffer = read_file_v1(file_name);
        network_configuration **net_conf = (network_configuration **)malloc(10*sizeof(struct network_config *));
        char **data = (char **)malloc(sizeof(char *));
	char *begining = (char *)malloc(3*sizeof(char));
	char *ending = (char *)malloc(3*sizeof(char));
        char *key;
        char *end_of_data;
        char *number_of_interface;
        char *t = strdup(": \0");
        char **c0;
        char **c1;
        char **m;
        char *p;
        char *c;
        char *interface_name;
        int i = 1;
        char *number = (char *)malloc(4*sizeof(char));
	int a = 0;
        system("echo \"$(ls -A /sys/class/net | wc -l)\" > number_of_interfaces.txt\0");
        file_name = strdup("./number_of_interfaces.txt\0");
        char *number_of_inter = read_file_v1(file_name);
        int number_of_interfaces = atoi(number_of_inter);
        data = strdup(" \0");
	while(i <= number_of_interfaces)
        {
                sprintf(number, "%s\0", convert_int_to_char(&i));
		begining = strconcatenate(strdup(number), strdup(": \0"));
		i = i +1;
		data = (char **)realloc(data, i*sizeof(char *));
                sprintf(number, "%s\0", convert_int_to_char(&i));
               	ending = strconcatenate(strdup(number), strdup(": \0"));
		data[i-2] = get_data_by_key_until_end_v0(buffer, begining, ending);
        	printf("%s\n", data[i-2]);
	}
	data[i-1] = '\0';
        //free(buffer);
        //free(file_name);
        //free(t);
        //free(interface_name);
        //free(number_of_inter);
        return net_conf;
}

int main()
{
        network_configuration **net_conf = get_network_conf();
        print_network_config(net_conf);
        return 0;
}
