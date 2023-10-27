FLAGS=-Wall -g


input_output.o: input_output.c input_output.h 
	gcc $(FLAGS) -c $^ $(lib)

install: input_output.o input_output.h
	echo "Compiling input_output ..."
	cp -v input_output.o ../../lib/input_output.o
	cp -v input_output.h ../../include/input_output.h
