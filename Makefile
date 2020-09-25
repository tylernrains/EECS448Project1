prog: main.o board.o player.o Executive.o display.o Ship.o AI.o
	g++ -g -std=c++11 -Wall main.o board.o player.o Executive.o display.o Ship.o AI.o -o Battleship

main.o: main.cpp Executive.o
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp player.o board.o display.o Ship.o AI.o
	g++ -g -std=c++11 -Wall -c Executive.cpp

board.o: board.h board.cpp
	g++ -g -std=c++11 -Wall -c board.cpp

player.o: player.h player.cpp board.o
	g++ -g -std=c++11 -Wall -c player.cpp

display.o: display.h display.cpp
	g++ -g -std=c++11 -Wall -c display.cpp

Ship.o: Ship.h Ship.cpp
	g++ -g -std=c++11 -Wall -c Ship.cpp

AI.o: AI.h AI.cpp player.o
	g++ -g -std=c++11 -Wall -c AI.cpp

clean:
	rm *.o Battleship
