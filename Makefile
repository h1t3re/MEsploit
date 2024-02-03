install: 
	cd stdlib && make install && cd ..
	cd modules/get_network_conf && make install && cd ../..
	
compile: install
	gcc -Wall -g lib/stdlib.o lib/get_network_conf.o MEsploit.c -o MEsploit
