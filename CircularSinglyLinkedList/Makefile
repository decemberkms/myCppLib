
output: main.o CSLL.o
	g++ main.o CSLL.o -o main

main.o: main.cpp
	g++ -c main.cpp

SLL.o: CSLL.cpp CSLL.hpp
	g++ -c CSLL.cpp

clean: 
	rm *.o main