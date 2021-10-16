CC = clang++

# -fstandalone-debug -> debug with gdb but compiled with clang
CFLAGS = -Wall -Wextra -std=c++17 -g -fstandalone-debug
LFLAGS = -lncurses

INCLUDE = include
SOURCE = src
BUILD = build

TARGET = $(BUILD)/binary

$(TARGET): $(BUILD)/menubar.o $(BUILD)/main.o
		$(CC) $(LFLAGS) -o $(TARGET) $(BUILD)/*.o

$(BUILD)/menubar.o: $(INCLUDE)/menu.hpp $(INCLUDE)/menubar.hpp $(SOURCE)/menubar.cpp
		$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SOURCE)/menubar.cpp -o $(BUILD)/menubar.o

$(BUILD)/main.o: $(INCLUDE)/menu.hpp $(INCLUDE)/menubar.hpp $(SOURCE)/main.cpp
		$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SOURCE)/main.cpp -o $(BUILD)/main.o

clean:
	rm -f $(BUILD)/*
