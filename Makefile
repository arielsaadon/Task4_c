CC = gcc
CFLAGS = -Wall -g -c
DEPS = trie.h
OBJ = trie.o main.o

all: frequency

frequency : $(OBJ)
	$(CC) $(OBJ) -o frequency

main.o : main.c $(DEPS)
	$(CC) $(CFLAGS) main.c

trie.o : trie.c $(DEPS)
	$(CC) $(CFLAGS) trie.c

.PHONY : clean all

clean :
	rm -f *.o  frequency
