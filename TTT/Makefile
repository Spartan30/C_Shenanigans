all: ttt main

ttt: TicTacToe.c TicTacToe.h
	gcc -std=c11 -pedantic -Wall -c TicTacToe.c -o TicTacToe.o

main: ttt Main.c
	gcc -std=c11 -pedantic -Wall Main.c TicTacToe.o -o TTT.exe

run: all
	./TTT.exe

clean:
	rm -f *.o *.exe