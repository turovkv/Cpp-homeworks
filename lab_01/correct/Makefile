

CFLAGS = -Wall -Wextra -Werror -I include

all: lab


bin:
	mkdir bin;
	mkdir obj;

lab: main.o io.o algorithm.o util.o bin
	gcc obj/main.o obj/io.o obj/algorithm.o obj/util.o -o bin/lab 

main.o: src/main.c bin
	gcc $(CFLAGS) -c src/main.c -o obj/main.o 

io.o: src/io.c bin
	gcc $(CFLAGS) -c src/io.c -o obj/io.o 

algorithm.o: src/algorithm.c bin
	gcc $(CFLAGS) -c src/algorithm.c -o obj/algorithm.o 

util.o: src/util.c bin
	gcc $(CFLAGS) -c src/util.c -o obj/util.o 


clean: 
	rm -rf  bin obj;



