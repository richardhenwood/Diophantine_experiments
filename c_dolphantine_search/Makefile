
INCLUDES=-I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include

CC=gcc
LIBS=-lm

CFLAGS=-g -Wall -pg
LDFLAGS=-lgmp -lglib-2.0

OBJECTS=search.o

all: search

search: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) $(LIBS) $^ -o $@ 

search.o: search.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


#simp_search: simp_search.o $(HASH_LIB_DIR)hashtable.o $(HASH_LIB_DIR)hashtable_itr.o
#	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@ -I$(HASH_LIB_DIR) -L$(HASH_LIB_DIR)
#
#tester: tester.o $(HASH_LIB_DIR)hashtable.o $(HASH_LIB_DIR)hashtable_itr.o
#	$(CC) $(CFLAGS) $(LIBS) $^ -o $@ -I$(HASH_LIB_DIR) -L$(HASH_LIB_DIR)

#hash_lib:
#	cd $(HASH_LIB_DIR); $(MAKE) hashtable.o

#all: tester 

#tester: hashtable.o tester.o hashtable_itr.o
#	gcc -g -Wall -O -lm -o tester hashtable.o hashtable_itr.o tester.o
#
#tester.o:	tester.c
#	gcc -g -Wall -O -c tester.c -o tester.o
#
#hashtable.o:	hashtable.c
#	gcc -g -Wall -O -c hashtable.c -o hashtable.o
#
#hashtable_itr.o: hashtable_itr.c
#	gcc -g -Wall -O -c hashtable_itr.c -o hashtable_itr.o
#
#tidy:
#	rm *.o
#
#clean: tidy
#	rm -f tester old_tester

#all: tester old_tester
#
#old_tester: hashtable_powers.o tester.o hashtable_itr.o
#	gcc -g -Wall -O -o old_tester hashtable_powers.o hashtable_itr.o tester.o
#
#hashtable_powers.o:	hashtable_powers.c
#	gcc -g -Wall -O -c hashtable_powers.c -o hashtable_powers.o
