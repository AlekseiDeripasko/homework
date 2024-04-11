# Назва компілятора
CC=g++

# Опції компіляції
CFLAGS=-c -Wall

# Опції лінкування
LDFLAGS=

# Назва вихідного файлу
EXECUTABLE=my_daemon

# Вихідний код
SOURCES=main.cpp

# Об'єктні файли
OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
