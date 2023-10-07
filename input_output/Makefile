FLAGS=-DUSECOLORS -Wall -g -DPRODUCTION 

lib = ../lib/mem.o

input_output.o: input_output.c input_output.h $(lib) 
	gcc $(FLAGS) -c $^ $(lib)

install: input_output.o input_output.h
	cp -v input_output.o ../lib/
	cp -v input_output.h ../include/
