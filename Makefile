e1: main.o Minesweeper.o Executive.o
	g++ -std=c++11 -g -Wall main.o Minesweeper.o Executive.o -o e1
main.o: main.cpp Minesweeper.cpp Executive.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Minesweeper.o: Minesweeper.h Minesweeper.cpp
	g++ -std=c++11 -g -Wall -c Minesweeper.cpp
Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o e1
