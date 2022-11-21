all:game

game:game_ncurses.o MainDriver.o Array.o
	g++ -std=c++11 -W -Wall -o game game_ncurses.o MainDriver.o Array.o -lncursesw

game_ncurses.o:game_ncurses.cpp
	g++ -std=c++11 -W -Wall -c -o game_ncurses.o game_ncurses.cpp

MainDriver.o:MainDriver.cpp
	g++ -std=c++11 -W -Wall -c -o MainDriver.o MainDriver.cpp

Array.o:Array.cpp
	g++ -std=c++11 -W -Wall -c -o Array.o Array.cpp
