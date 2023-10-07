all : spliter mem input_output

FLAGS=-DUSECOLORS -Wall -g -DPRODUCTION -o
lib= lib/spliter.o lib/mem.o lib/input_output.o
DEP= spliter mem input_output

compile: MEsploit.c $(lib) $(DEP)
	gcc $(FLAGS) MEsploit $< $(lib) -I lib 

exec: compile
	./MEsploit

