CC = gcc
CFLAGS = -Wall -Wextra

all: my_program

my_program: main.o queue.o
	$(CC) $(CFLAGS) -o my_program main.o queue.o

main.o: main.c queue.h
	$(CC) $(CFLAGS) -c -o main.o main.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c -o queue.o queue.c

clean:
	rm -f my_program main.o queue.o

run:
	./my_program.exe