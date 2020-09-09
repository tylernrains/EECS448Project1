prog: main.o board.o player.o display.o
	g++ -g -std=c++11 -Wall main.o board.o player.o display.o -o program

display.o: display.h display.cpp
	g++ -g -std=c++11 -Wall -c display.cpp

board.o: board.h board.cpp
	g++ -g -std=c++11 -Wall -c board.cpp

player.o: player.h player.cpp board.o
	g++ -g -std=c++11 -Wall -c player.cpp

main.o: main.cpp board.o player.o 
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *.o program


