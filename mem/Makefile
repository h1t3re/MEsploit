FLAGS=-DUSECOLORS -Wall -g -DPRODUCTION 

mem.o: mem.c mem.h 
	gcc $(FLAGS) -c $^

install: mem.o mem.h
	cp -v mem.o ../lib/
	cp -v mem.h ../include/
