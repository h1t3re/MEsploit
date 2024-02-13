compile_get_network_configuration: get_network_configuration/Makefile get_network_configuration/get_network_configuration.c get_network_configuration/get_network_configuration.h
	cd get_network_configuration; make install; cd ..

compile_forge_arp_packet: forge_packet/Makefile forge_packet/forge_arp_packet.c forge_packet/forge_arp_packet.h
	cd forge_packet; make install; cd ..

install: compile_get_network_configuration compile_forge_arp_packet
