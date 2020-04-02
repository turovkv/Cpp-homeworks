CFLAGS = -fsanitize=address  -fsanitize=undefined -fsanitize=leak -I include
#CFLAGS = -Wall -Wextra -Werror -I include
#CFLAGS =  -I include



all: hw

bin:
	mkdir bin;
	mkdir obj;

hw: bmp.o main.o | bin
	gcc $(CFLAGS) obj/bmp.o obj/main.o -o bin/hw

bmp.o: src/bmp.c | bin
	gcc $(CFLAGS) -c src/bmp.c -o obj/bmp.o 

main.o: src/main.c | bin
	gcc $(CFLAGS) -c src/main.c -o obj/main.o 

clean: 
	rm -rf  bin obj;
