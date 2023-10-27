FLAGS=-DUSECOLORS -Wall -g -DPRODUCTION 

strlen.o: strlen.c strlen.h 
	gcc $(FLAGS) -c $^

install: strlen.o strlen.h
	echo "Compiling strlen ..."
	cp -v strlen.o ../../lib/strlen.o
	cp -v strlen.h ../../include/strlen.h
