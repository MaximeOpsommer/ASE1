CC=gcc
CFLAGS=-Wall -O
LDFLAGS=
EXEC=tp1_breuzon_opsommer
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

tp1_breuzon_opsommer: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: try.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o core

mrproper: clean
	rm -f $(EXEC)
