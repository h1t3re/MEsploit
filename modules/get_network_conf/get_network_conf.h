typedef struct net_config{
        char *name;
        char *mac_addr;
        char **ip_addr;
        int number;
}network_config;
int print_network_interface(network_config *net_conf);
int print_network_config(network_config **net_conf);
int free_network_config_struct(network_config **net_conf);
network_config **get_network_conf();
