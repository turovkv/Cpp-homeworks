
#CFLAGS = -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined -I include
CFLAGS = -Wall -Wextra -Werror -I include



all: lab

bin:
	mkdir bin;
	mkdir obj;

lab: clist.o main.o | bin
	gcc $(CFLAGS) obj/clist.o obj/main.o -o bin/lab 

clist.o: src/clist.c | bin
	gcc $(CFLAGS) -c src/clist.c -o obj/clist.o 
main.o: src/main.c | bin
	gcc $(CFLAGS) -c src/main.c -o obj/main.o 

clean: 
	rm -rf  bin obj;
