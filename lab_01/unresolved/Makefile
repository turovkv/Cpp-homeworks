.PHONY: all clean

CFLAGS = -Wall -Wextra -Werror -g -I include
#CFLAGS = -I include

all: lab

clean: 
	rm -rf  bin obj

directories:
	mkdir bin
	mkdir obj

main.o: src/main.c directories
	gcc $(CFLAGS) -c src/main.c -o obj/main.o 

io.o: src/main.c directories
	gcc $(CFLAGS) -c src/io.c -o obj/io.o 

algorithm.o: src/main.c directories
	gcc $(CFLAGS) -c src/algorithm.c -o obj/algorithm.o 

util.o: src/main.c directories
	gcc $(CFLAGS) -c src/util.c -o obj/util.o 

lab: main.o io.o algorithm.o util.o directories
	gcc obj/main.o obj/io.o obj/algorithm.o obj/util.o -o bin/lab 




