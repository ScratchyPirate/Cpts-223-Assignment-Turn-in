output: main.o functions.o ListMyJosephus.o VectorMyJosephus.o Destinations.o TestListMyJosephus.o TestVectorMyJosephus.o
	g++ main.o functions.o ListMyJosephus.o VectorMyJosephus.o Destinations.o TestListMyJosephus.o TestVectorMyJosephus.o -g -Wall -stdc++=11 -o main

main.o: main.cpp VectorMyJosephus.hpp
	g++ -c main.cpp

functions.o: functions.cpp declarations.hpp
	g++ -c functions.cpp

ListMyJosephus.o: ListMyJosephus.cpp ListMyJosephus.hpp
	g++ -c ListMyJosephus.cpp

VectorMyJosephus.o: VectorMyJosephus.cpp VectorMyJosephus.hpp
	g++ -c VectorMyJosephus.cpp

TestListMyJosephus.o: TestListMyJosephus.cpp ListMyJosephus.hpp
	g++ -c TestListMyJosephus.cpp

TestVectorMyJosephus.o: TestVectorMyJosephus.cpp VectorMyJosephus.hpp
	g++ -c TestVectorMyJosephus.cpp

Destinations.o: Destinations.cpp Destinations.hpp
	g++ -c Destinations.cpp

clean:
	rm *.o output


