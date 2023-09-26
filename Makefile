all: test/testa_velha.cpp   velha.cpp headers/velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o test/testa_velha.cpp -o testa_velha
	cd test
	./testa_velha

clear:
	rm -rf *.rpt *.o *.exe *.gc* testa_velha

compile: test/testa_velha.cpp   velha.cpp headers/velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o test/testa_velha.cpp -o testa_velha

velha.o : velha.cpp headers/velha.hpp
	g++ -std=c++11 -Wall -c velha.cpp
	
testa_velha: 	test/testa_velha.cpp   velha.cpp headers/velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o test/testa_velha.cpp -o testa_velha
	
test: testa_velha
	cd test/
	./testa_velha
	
cpplint: test/testa_velha.cpp   velha.cpp headers/velha.hpp
	cpplint   --exclude=catch.hpp --exclude=cpplint.py --exclude=README.md --exclude=velha.o *.*
	
gcov: test/testa_velha.cpp   velha.cpp headers/velha.hpp 
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c velha.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage velha.o test/testa_velha.cpp -o testa_velha
	./testa_velha
	gcov *.cpp	
	 
debug: test/testa_velha.cpp   velha.cpp headers/velha.hpp 
	g++ -std=c++11 -Wall -g -c velha.cpp
	g++ -std=c++11 -Wall  -g velha.o test/testa_velha.cpp -o testa_velha
	gdb testa_velha
	
cppcheck: test/testa_velha.cpp   velha.cpp headers/velha.hpp
	cppcheck  --enable=warning .

valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_velha
