CXXFLAGS = -Wall -Wextra -Werror -I include


all: lab

bin:
	mkdir bin;
	mkdir obj;

lab: shared_ptr.o matrix.o main.o | bin
	g++ $(CXXFLAGS) obj/shared_ptr.o obj/matrix.o obj/main.o -o bin/lab

shared_ptr.o: src/shared_ptr.cpp | bin
	g++ $(CXXFLAGS) -c src/shared_ptr.cpp -o obj/shared_ptr.o
matrix.o: src/matrix.cpp | bin
	g++ $(CXXFLAGS) -c src/matrix.cpp -o obj/matrix.o
main.o: src/main.cpp | bin
	g++ $(CXXFLAGS) -c src/main.cpp -o obj/main.o

clean:
	rm -rf  bin obj;
