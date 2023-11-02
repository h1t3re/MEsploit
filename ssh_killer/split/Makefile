FLAGS=-Wall -g

split.o: split.c split.h
	gcc $(FLAGS) -c $^ ../lib/strncmp.o ../lib/strlen.o

install: split.o split.h
	cp -v split.o ../lib/split.o
	cp -v split.h ../include/split.h
