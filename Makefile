CC=gcc
CFLAGS=`sdl2-config --cflags --libs`

all: compile

compile: main.o
	$(CC) main.o -o main $(CFLAGS)

main.o: main.c
	$(CC) main.c -c 

clean:
	rm -rf *.o
