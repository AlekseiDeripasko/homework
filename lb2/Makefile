CC=g++
CFLAGS=-Wall -Wextra -pedantic

all: launcher info_printer test_program

launcher: launcher.cpp
	$(CC) $(CFLAGS) -o launcher launcher.cpp

info_printer: info_printer.cpp
	$(CC) $(CFLAGS) -o info_printer info_printer.cpp

test_program: test_program.cpp
	$(CC) $(CFLAGS) -o test_program test_program.cpp

clean:
	rm -f launcher info_printer test_program

