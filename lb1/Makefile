SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj

all: main

main: $(OBJ_DIR)/main.o $(OBJ_DIR)/A.o $(OBJ_DIR)/B.o
	gcc -o main $(OBJ_DIR)/main.o $(OBJ_DIR)/A.o $(OBJ_DIR)/B.o

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(INC_DIR)/A.h $(INC_DIR)/B.h | $(OBJ_DIR)
	gcc -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR)/A.o: $(SRC_DIR)/A.c $(INC_DIR)/A.h | $(OBJ_DIR)
	gcc -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR)/B.o: $(SRC_DIR)/B.c $(INC_DIR)/B.h | $(OBJ_DIR)
	gcc -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) main
