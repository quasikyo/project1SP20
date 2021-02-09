compile: Student.o UnsortedListDriver.cpp
	g++ -std=c++14 -Wall -pedantic-errors -O0 -o list_driver Student.o UnsortedListDriver.cpp

Student.o: Student.h Student.cpp
	g++ -std=c++14 -Wall -pedantic-errors -O0 -c Student.cpp

run: list_driver
	./list_driver

clean:
	rm *.o list_driver

