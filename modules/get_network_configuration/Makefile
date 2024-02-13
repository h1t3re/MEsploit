compile: ../../lib/stdlib.o ../../include/stdlib.h get_network_configuration.c get_network_configuration.h
	gcc -Wall -g -c get_network_configuration.c

install: compile get_network_configuration.h get_network_configuration.o
	cp -v get_network_configuration.o ../../lib/get_network_configuration.o
	cp -v get_network_configuration.h ../../include/get_network_configuration.h
