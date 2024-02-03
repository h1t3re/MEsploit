compile: ../../lib/stdlib.o ../../include/stdlib.h get_network_conf.c get_network_conf.h
	gcc -Wall -g -c get_network_conf.c

install: compile get_network_conf.h get_network_conf.o
	cp -v get_network_conf.o ../../lib/get_network_conf.o
	cp -v get_network_conf.h ../../include/get_network_conf.h
