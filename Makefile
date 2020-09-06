prog: main.o Board.o
	g++ -g -std=c++11 -Wall main.o Board.o -o program

Board.o: Board.h Board.cpp
	g++ -g -std=c++11 -Wall -c Board.cpp

main.o: main.cpp Board.h Board.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *.o program


