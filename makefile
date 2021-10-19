GCC = gcc
FLAGS = -ansi -pedantic -Wall -std=c99 -pthread
C_FLAGS = -fopenmp -lm
PROGRAMAS = POSIX OPENMP

all: $(PROGRAMAS)

POSIX:
	$(GCC) $(FLAGS) functionsPOSIX.c -c $(C_FLAGS)
	$(GCC) $(FLAGS) ctimePOSIX.c -c $(C_FLAGS)
	$(GCC) $(FLAGS) $@.c -c $(C_FLAGS)
	$(GCC) $(FLAGS) -o $@ $@.o functionsPOSIX.o ctimePOSIX.o $(C_FLAGS)

OPENMP:
	$(GCC) $(FLAGS) functionsOPENMP.c -c $(C_FLAGS)
	$(GCC) $(FLAGS) ctimeOPENMP.c -c $(C_FLAGS)
	$(GCC) $(FLAGS) $@.c -c $(C_FLAGS)
	$(GCC) $(FLAGS) -o $@ $@.o functionsOPENMP.o ctimeOPENMP.o $(C_FLAGS)

clean:
	$(RM) $@ *.o
	$(RM) $@ $
	$(RM) $(PROGRAMAS) $
