FLAGS=-Wall -g

LIB: ../../lib/strncmp.o ../../lib/strlen.o

INCLUDE: ../../include/strncmp.h ../../include/strlen.h

spliter.o: spliter.c spliter.h
	echo "Compiling spliter ..."
	gcc $(FLAGS) -c $^ ../../lib/strncmp.o ../../lib/strlen.o

install: spliter.o spliter.h
	echo "Coping files ... "
	cp -v spliter.o ../../lib/spliter.o
	cp -v spliter.h ../../include/spliter.h
