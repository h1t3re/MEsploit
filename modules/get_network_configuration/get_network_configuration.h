typedef struct network_config{
        char *name;
        char *mac_addr;
        char **ip_addr;
        int number;
}network_configuration;
int print_network_interface(network_configuration *net_config);
int print_network_configuration(network_configuration **net_config);
int free_network_config_struct(network_configuration **net_config);
network_configuration **get_network_configuration();
