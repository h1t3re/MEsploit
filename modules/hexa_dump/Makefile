FLAGS=-Wall -g

hexa_dump.o: hexa_dump.c hexa_dump.h 
	gcc $(FLAGS) -c $^

install: hexa_dump.o hexa_dump.h
	echo "Compiling hexa_dump ..."
	cp -v hexa_dump.o ../../lib/hexa_dump.o
	cp -v hexa_dump.h ../../include/hexa_dump.h
