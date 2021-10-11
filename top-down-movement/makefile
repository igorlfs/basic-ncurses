CC = clang++
# -fstandalone-debug -> debug with gdb but compiled with clang
CFLAGS = -Wall -Wextra -std=c++17 -g -fstandalone-debug
LFLAGS = -lncurses
TARGET = bin
BUILD = ./build

$(TARGET): $(BUILD)/player.o $(BUILD)/main.o
		$(CC) $(LFLAGS) -o $(TARGET) $(BUILD)/*.o

$(BUILD)/player.o: player.hpp player.cpp
		$(CC) $(CFLAGS) -c player.cpp -o $(BUILD)/player.o

$(BUILD)/main.o: player.hpp main.cpp
		$(CC) $(CFLAGS) -c main.cpp -o $(BUILD)/main.o
