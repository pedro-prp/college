CC := g++
CFLAGS := -Wall -std=c++11

SRCFILES := $(wildcard src/*.cpp)

all: $(SRCFILES:src/%.cpp=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/app

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*
	rm -rf imagens/jose.pgm
	rm -rf imagens/jose.ppm
	rm -rf imagens/cripPgm.txt
	rm -rf imagens/cripPpmPrim.txt
	rm -rf imagens/cripPpmSec.txt
	rm -rf imagens/descripPgm.txt

run:
	bin/app


