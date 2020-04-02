
CFLAGS = -Wall -Wextra -Werror -I include

all: lab

bin:
	mkdir bin;
	mkdir obj;

lab: test.o test_str.o str.o | bin
	gcc $(CFLAGS) obj/test.o obj/test_str.o obj/str.o -o bin/lab 

test.o: src/test.c | bin
	gcc $(CFLAGS) -c src/test.c -o obj/test.o 

test_str.o: src/test_str.c | bin
	gcc $(CFLAGS) -c src/test_str.c -o obj/test_str.o 

str.o: src/str.c | bin
	gcc $(CFLAGS) -c src/str.c -o obj/str.o 


clean: 
	rm -rf  bin obj;
