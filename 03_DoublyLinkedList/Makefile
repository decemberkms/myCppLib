
output: main.o DSSL.o
	g++ main.o DSSL.o -o main

main.o: main.cpp
	g++ -c main.cpp

SLL.o: DSSL.cpp DSSL.hpp
	g++ -c DSSL.cpp

clean: 
	rm *.o main