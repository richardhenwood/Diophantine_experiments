#@echo "don't forget to load the Intel MKL module!!!!!!!!!!!!!!!!!"

MKLROOT=/apps/intel/cmkl/10.0.2.018
MKLPATH=-L$(MKLROOT)/lib/em64
MKLINCLUDE=-I$(MKLROOT)/include
DEFAULT_CC=icc
CC=mpic++ -g
CFLAGS=-c -Wall -g
LDFLAGS=-lgmp -g# -lmkl_intel_thread -lmkl_solver -lmkl_core -liomp5 -lpthread -lm -lguide
#LDFLAGS=-lmkl -lmkl_intel_thread -lmkl_solver -lmkl_core -liomp5 -lpthread -lm -lguide

SOURCES=dolphine_search.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=dolphine_search


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(MKLPATH) $(LDFLAGS) -o $@ 

.cpp.o:
	$(CC) $(MKLINCLUDE) $(CFLAGS) $< -o $@

#bsub -q scarf-intel -n 8 -a openmpi mpirun -np 8 ./map_numbers3 2 3 -5 -7 8000 0 2500000 /work/scratch/rjh3
