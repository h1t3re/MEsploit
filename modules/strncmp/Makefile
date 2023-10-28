FLAGS=-Wall -g

strncmp.o: strncmp.c strncmp.h 
	gcc $(FLAGS) -c $^

install: strncmp.o strncmp.h
	echo "Compiling strncmp ..."
	cp -v strncmp.o ../../lib/strncmp.o
	cp -v strncmp.h ../../include/strncmp.h

test: install test_strncmp.c ../../lib/strncmp.o ../../lib/strlen.o
	make install
	gcc -Wall -g test_strncmp.c ../../lib/strncmp.o ../../lib/strlen.o -o test_strncmp
	./test_strncmp
