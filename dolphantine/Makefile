
# Preprocessor flags to encourage good practice!
# I relax the pedantic rules for 'long long' with -Wno-long-long
PREPROCESSOR = -ansi -pedantic -Wall -Werror -Wno-long-long -Wshadow 

# these are my 'optimised for speed' Flags
# The first version are commented out... My current experience
# is that these slow things down if anything.
#OPTIMIZEDFLAGS = $(PREPROCESSOR) -O5 -ffast-math -funroll-all-loops -fpeel-loops -ftracer -funswitch-loops -funit-at-a-time -ftree-vectorize
# Just stick with -O5:
OPTIMIZEDFLAGS = $(PREPROCESSOR) -O5 

# these are my debugging flags
DEBUGFLAGS = $(PREPROCESSOR) -g -ggdb 
CFLAGS = $(DEBUGFLAGS)
LIBS = -lgmp -lm -g
CC = mpicc

objs =  search.o


.PHONY: all test clean

all: $(objs) search

debug:
	$(MAKE) CFLAGS="$(DEBUGFLAGS)"

optimized:
	$(MAKE) CFLAGS="$(OPTIMIZEDFLAGS)"

search: search.c
	$(CC) -o $@ $@.c $(LIBS)

.o: 
	$(CC) $(CFLAGS) -c $*.c

clean:
	rm *.o
	rm ./search

test:
	mpirun -np 1 ./search 2 3 -5 -7 10 0 25 /tmp/log
	mpirun -np 4 ./search 2 3 -5 -7 100 0 25000 /tmp/log2


##bsub -q scarf-intel -n 8 -a openmpi mpirun -np 8 ./map_numbers3 2 3 -5 -7 8000 0 2500000 /work/scratch/rjh3

