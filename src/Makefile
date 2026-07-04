CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Iinclude

SDL_CFLAGS := $(shell pkg-config --cflags sdl3)
SDL_LIBS := $(shell pkg-config --libs sdl3)

SRC = src/main.c
TARGET = viewer

all:
	$(CC) $(CFLAGS) $(SRC) $(SDL_CFLAGS) $(SDL_LIBS) -o $(TARGET)

clean:
	rm -f $(TARGET)
