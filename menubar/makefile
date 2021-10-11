CC = clang++
# -fstandalone-debug -> debug with gdb but compiled with clang
CFLAGS = -Wall -Wextra -std=c++17 -g -fstandalone-debug
LFLAGS = -lncurses
TARGET = bin
BUILD = ./build

$(TARGET): $(BUILD)/menubar.o $(BUILD)/main.o
		$(CC) $(LFLAGS) -o $(TARGET) $(BUILD)/*.o

$(BUILD)/menubar.o: menu.hpp menubar.hpp menubar.cpp
		$(CC) $(CFLAGS) -c menubar.cpp -o $(BUILD)/menubar.o

$(BUILD)/main.o: menu.hpp menubar.hpp main.cpp
		$(CC) $(CFLAGS) -c main.cpp -o $(BUILD)/main.o
