all : modules/spliter modules/mem modules/input_output

FLAGS=-Wall -g -o
lib= lib/spliter.o lib/input_output.o lib/print.o
DEP= include/spliter.h include/input_output.h include/print.h

compile: MEsploit.c $(lib) $(DEP)
	gcc $(FLAGS) MEsploit $< $(lib) $(DEP) -I lib 

exec: compile
	./MEsploit

