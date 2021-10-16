CC = clang++

# -fstandalone-debug -> debug with gdb but compiled with clang
CFLAGS = -Wall -Wextra -std=c++17 -g -fstandalone-debug
LFLAGS = -lncurses

INCLUDE = include
SOURCE = src
BUILD = build

TARGET = $(BUILD)/binary

$(TARGET): $(BUILD)/player.o $(BUILD)/main.o
		$(CC) $(LFLAGS) -o $(TARGET) $(BUILD)/*.o

$(BUILD)/player.o: $(INCLUDE)/player.hpp $(SOURCE)/player.cpp
		$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SOURCE)/player.cpp -o $(BUILD)/player.o

$(BUILD)/main.o: $(INCLUDE)/player.hpp $(SOURCE)/main.cpp
		$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SOURCE)/main.cpp -o $(BUILD)/main.o

clean:
	rm -f $(BUILD)/*
