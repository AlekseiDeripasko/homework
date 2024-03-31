all: main

main: main.o A_equation.o B_equation.o
	g++ -o main main.o A_equation.o B_equation.o

main.o: main.cpp A_equation.h B_equation.h
	g++ -c main.cpp

A_equation.o: A_equation.cpp A_equation.h
	g++ -c A_equation.cpp

B_equation.o: B_equation.cpp B_equation.h
	g++ -c B_equation.cpp

clean:
	rm -f *.o main
