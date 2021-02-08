main: Student.o UnsortedListDr.cpp
	g++ -std=c++14 -Wall -pedantic-errors -O0 -o list_driver Student.o UnsortedListDr.cpp

Student.o: Student.h Student.cpp
	g++ -std=c++14 -Wall -pedantic-errors -O0 -c Student.cpp

