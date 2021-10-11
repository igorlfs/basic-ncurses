CC = clang++
# -fstandalone-debug -> debug with gdb but compiled with clang
CLAFGS = -lncurses -Wall -Wextra -std=c++17 -g -fstandalone-debug
TARGET = bin
SRC = src.cpp

$(TARGET): $(SRC)
		$(CC) $(CLAFGS) -o $(TARGET) $(SRC)
