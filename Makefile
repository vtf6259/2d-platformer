.PHONY: all run clean
all: main
main: build/main.o build/player.o build/level.o libjansson.a
	gcc -ggdb -o build/2d-platformer build/main.o build/player.o build/level.o -lraylib -lm

run: main
	./build/2d-platformer
clean:
	rm -r jansson-2.15.0 libjansson.a build/2d-platformer build/main.o build/player.o build/level.o

build/main.o: src/main.c
	gcc -ggdb -Wall -Werror -Isrc/include -c -o build/main.o src/main.c
build/player.o: src/player.c src/include/player.h
	gcc -ggdb -Wall -Werror -Isrc/include -c -o build/player.o src/player.c
build/level.o: src/level.c src/include/level.h
	gcc -ggdb -Wall -Werror -Isrc/include -c -o build/level.o src/level.c

libjansson.a:
	-rm v2.15.0.tar.gz
	./build_jansson.sh

