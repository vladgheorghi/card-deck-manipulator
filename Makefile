CC=gcc
CFLAGS=-Wall -Wextra -std=c99
DEBUG=-g
MEMLEAK=valgrind
MEMLEAKFLAGS=--track-origins=yes --leak-check=full --show-leak-kinds=all

build:
	$(CC) $(CFLAGS) $(DEBUG) *.c -o tema1

run:
	./tema1

clean:
	rm -rf *.o tema1

valgrind:
	$(MEMLEAK) $(MEMLEAKFLAGS) ./tema1

pack:
	zip 312CA_GheorghiuVlad_Tema1SD.zip README Makefile *.c *.h