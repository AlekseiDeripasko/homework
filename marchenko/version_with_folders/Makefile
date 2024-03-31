SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj

CC := g++

CFLAGS := -Wall -Wextra -std=c++11

all: main

main: $(OBJ_DIR)/main.o $(OBJ_DIR)/A_equation.o $(OBJ_DIR)/B_equation.o
	$(CC) $(CFLAGS) -o main $^

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/A_equation.h $(INC_DIR)/B_equation.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR)/A_equation.o: $(SRC_DIR)/A_equation.cpp $(INC_DIR)/A_equation.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR)/B_equation.o: $(SRC_DIR)/B_equation.cpp $(INC_DIR)/B_equation.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) main
