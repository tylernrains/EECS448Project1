prog: main.o Board.o Player.o Executive.o
	g++ -g -std=c++11 -Wall main.o Board.o Player.o Executive.o -o program

main.o: main.cpp Executive.o
	g++ -g -std=c++11 -Wall -c main.cpp

Board.o: Board.h Board.cpp
	g++ -g -std=c++11 -Wall -c Board.cpp

Player.o: player.h player.cpp Board.o
	g++ -g -std=c++11 -Wall -c player.cpp

Executive.o: Executive.h Executive.cpp Player.o Board.o
	g++ -g -std=c++11 -Wall -c Executive.cpp

clean:
	rm *.o program


