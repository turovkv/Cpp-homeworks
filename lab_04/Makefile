
#CFLAGS =  -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined -I include
CFLAGS = -Wall -Wextra -Werror -I include



all: lab

bin:
	mkdir bin;
	mkdir obj;

lab: mergesort.o main.o | bin
	gcc $(CFLAGS) obj/mergesort.o obj/main.o -o bin/lab 

mergesort.o: src/mergesort.c | bin
	gcc $(CFLAGS) -c src/mergesort.c -o obj/mergesort.o 
main.o: src/main.c | bin
	gcc $(CFLAGS) -c src/main.c -o obj/main.o 

clean: 
	rm -rf  bin obj;
