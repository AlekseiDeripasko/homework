SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj

CC := g++

CFLAGS := -Wall -Wextra -std=c++11

all: main

main: $(OBJ_DIR)/main.o $(OBJ_DIR)/first.o $(OBJ_DIR)/second.o
	$(CC) $(CFLAGS) -o main $^

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/first.h $(INC_DIR)/second.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR)/first.o: $(SRC_DIR)/first.cpp $(INC_DIR)/first.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR)/second.o: $(SRC_DIR)/second.cpp $(INC_DIR)/second.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) main
