compile_forge_arp_packet: ../../lib/stdlib.o ../../include/stdlib.h forge_arp_packet.c forge_arp_packet.h
	gcc -Wall -c forge_arp_packet.c -o forge_arp_packet.o

install: compile_forge_arp_packet
	cp -v ./forge_arp_packet.h ../../include/forge_arp_packet.h
	cp -v ./forge_arp_packet.o ../../lib/forge_arp_packet.o
