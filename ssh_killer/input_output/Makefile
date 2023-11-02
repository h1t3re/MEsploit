FLAGS=-Wall -g


input_output.o: input_output.c input_output.h 
	gcc $(FLAGS) -c $^ $(lib)

install: input_output.o input_output.h
	cp -v input_output.o ../lib/input_output.o
	cp -v input_output.h ../include/input_output.h

test: test_input_output.c install ../lib/strncmp.o ../lib/input_output.o
	gcc $(FLAGS) test_input_output.c ../lib/strncmp.o ../lib/input_output.o -o test_input_output
