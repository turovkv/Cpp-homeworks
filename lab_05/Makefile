CFLAGS = -Wall -Wextra -Werror -I include



all: lab

bin:
	mkdir bin;
	mkdir obj;

lab: clist.o point_list.o main.o | bin
	gcc $(CFLAGS) obj/clist.o obj/point_list.o obj/main.o -o bin/lab 

clist.o: src/clist.c | bin
	gcc $(CFLAGS) -c src/clist.c -o obj/clist.o 
point_list.o: src/point_list.c | bin
	gcc $(CFLAGS) -c src/point_list.c -o obj/point_list.o 
main.o: src/main.c | bin
	gcc $(CFLAGS) -c src/main.c -o obj/main.o 

clean: 
	rm -rf  bin obj;
