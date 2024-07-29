
INCLUDES=-I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include

CC=gcc
LIBS=-lm

CFLAGS=-g -Wall -pg
LDFLAGS=-lgmp -lglib-2.0

OBJECTS=hash_test.o

all: hash_test

hash_test: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) $(LIBS) $^ -o $@ 

hash_test.o: hash_test.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

