FLAGS=-DUSECOLORS -Wall -g -DPRODUCTION 

spliter.o: spliter.c spliter.h 
	gcc $(FLAGS) -c $^

install: spliter.o spliter.h
	cp -v spliter.o ../lib/
	cp -v spliter.h ../include/
