CXXFLAGS = -Wall -Wextra -Werror -I include -g 
#CXXFLAGS = -Wall -Wextra -Werror -I include -g  -fsanitize=address -fsanitize=undefined -fsanitize=leak


all: lab

bin:
	mkdir bin;
	mkdir obj;

lab: Scheme.o Figure.o Rectangle.o Circle.o main.o | bin
	g++ $(CXXFLAGS) obj/Scheme.o obj/Figure.o obj/Rectangle.o obj/Circle.o obj/main.o -o bin/lab

Scheme.o: src/Scheme.cpp | bin
	g++ $(CXXFLAGS) -c src/Scheme.cpp -o obj/Scheme.o
Figure.o: src/Figure.cpp | bin
	g++ $(CXXFLAGS) -c src/Figure.cpp -o obj/Figure.o
Rectangle.o: src/Rectangle.cpp | bin
	g++ $(CXXFLAGS) -c src/Rectangle.cpp -o obj/Rectangle.o
Circle.o: src/Circle.cpp | bin
	g++ $(CXXFLAGS) -c src/Circle.cpp -o obj/Circle.o
main.o: src/main.cpp | bin
	g++ $(CXXFLAGS) -c src/main.cpp -o obj/main.o

clean:
	rm -rf  bin obj;
