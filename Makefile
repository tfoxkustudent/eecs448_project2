MineSweeper: main.o Executive.o Minesweeper.o
	g++ -std=c++11 -g -O0 -Wall main.o Minesweeper.o Executive.o -o MineSweeper

main.o: main.cpp Executive.cpp Minesweeper.cpp
	g++ -std=c++11 -g -O0 -Wall -c main.cpp

Minesweeper.o: Minesweeper.h Minesweeper.cpp
	g++ -std=c++11 -g -O0 -Wall -c Minesweeper.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -O0 -Wall -c Executive.cpp




clean:
	rm *.o MineSweeper
