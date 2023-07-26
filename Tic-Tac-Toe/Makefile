COMPILER=g++
COMPILER_FLAGS=-Wall -Wextra -Wconversion -Wuninitialized -Werror
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

default: main.o Board.o
	${COMPILER} main.o Board.o -o window.out ${COMPILER_FLAGS} ${LIBS} && ./window.out

main.o: main.cpp
	${COMPILER} -c main.cpp

Board.o: Board.cpp
	${COMPILER} -c Board.cpp

build: main.o Board.o
	${COMPILER} main.o Board.o -o window.out ${COMPILER_FLAGS} ${LIBS}
