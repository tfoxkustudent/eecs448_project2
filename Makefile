MineSweeper: main.o Minesweeper.o
	g++ -std=c++11 -g -Wall main.o Minesweeper.o -o MineSweeper

main.o: main.cpp Minesweeper.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Minesweeper.o: Minesweeper.h Minesweeper.cpp
	g++ -std=c++11 -g -Wall -c Minesweeper.cpp

clean:
	rm *.o MineSweeper
