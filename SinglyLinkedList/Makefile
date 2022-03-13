
output: main.o SLL.o
	g++ main.o SLL.o -o output

main.o: main.cpp
	g++ -c main.cpp

SLL.o: SLL.cpp SLL.hpp
	g++ -c SLL.cpp

clean: 
	rm *.o output