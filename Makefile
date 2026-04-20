.PHONY: all run clean
all: main
main: build/main.o build/player.o build/level.o
	gcc -ggdb -o build/2d-platformer build/main.o build/player.o build/level.o -lraylib -lm

run: main
	./build/2d-platformer
clean:
	rm -r jansson-2.15.0  build/2d-platformer build/main.o build/player.o build/level.o

build/main.o: src/main.cpp
	gcc -ggdb -Wall -Werror -Isrc/include -c -o build/main.o src/main.cpp
build/player.o: src/player.cpp src/include/player.h
	gcc -ggdb -Wall -Werror -Isrc/include -c -o build/player.o src/player.cpp
build/level.o: src/level.cpp src/include/level.h
	gcc -ggdb -Wall -Werror -Isrc/include -c -o build/level.o src/level.cpp


