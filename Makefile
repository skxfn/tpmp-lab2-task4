# Makefile for tpmp-lab2-task4 (Movie genres)

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/movie.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/movie.o
TARGET = $(BIN_DIR)/movie

all: dirs $(TARGET)

dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/movie.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/movie.o: $(SRC_DIR)/movie.c $(SRC_DIR)/movie.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/movie.c -o $(OBJ_DIR)/movie.o

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

check:
	@echo "Nothing to be done for 'check'."

distcheck:
	@echo "Nothing to be done for 'distcheck'."

.PHONY: all dirs clean check distcheck
