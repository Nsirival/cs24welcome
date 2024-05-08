CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

# These targets don't create any files:
.PHONY: all clean

all: main

main: main.o AST.o Nodes.o Stack.o
	${CXX} $(CXXFLAGS) -o $@ $+

main.o: main.cpp AST.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Nodes.o: Nodes.cpp Nodes.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

AST.o: AST.cpp AST.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

Stack.o: Stack.cpp Stack.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -f main main.o Nodes.o AST.o Stack.o