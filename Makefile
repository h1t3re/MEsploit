compile_stdlib: stdlib/stdlib.c stdlib/stdlib.h	
	cd stdlib; make install; cd ..

compile_modules: modules/
	cd modules; make install; cd ..

compile: compile_stdlib compile_modules
	gcc -Wall -g lib/stdlib.o lib/get_network_configuration.o lib/forge_arp_packet.o MEsploit.c -o MEsploit
