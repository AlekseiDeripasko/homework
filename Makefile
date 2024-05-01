CXX=g++
CXXFLAGS=-Wall

all: client server

client: client.o
	$(CXX) $(CXXFLAGS) -o client client.o

server: server.o
	$(CXX) $(CXXFLAGS) -o server server.o

client.o: client.cpp
	$(CXX) $(CXXFLAGS) -c client.cpp

server.o: server.cpp
	$(CXX) $(CXXFLAGS) -c server.cpp

clean:
	rm -f client server *.o
