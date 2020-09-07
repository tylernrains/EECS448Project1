prog: main.o Board.o
	g++ -g -std=c++11 -Wall main.o Board.o Player.o -o program

Board.o: Board.h Board.cpp
	g++ -g -std=c++11 -Wall -c Board.cpp

Player.o: player.h player.cpp Board.o
	g++ -g -std=c++11 -Wall -c player.cpp

main.o: main.cpp Board.o Player.o
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *.o program


