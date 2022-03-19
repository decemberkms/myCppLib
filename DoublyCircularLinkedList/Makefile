
output: main.o List.o
	g++ main.o List.o -o main

main.o: main.cpp
	g++ -c main.cpp

List.o: List.cpp List.hpp
	g++ -c List.cpp

clean: 
	rm *.o main