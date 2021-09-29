CC = g++
CFLAGS = -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

all: a.out

a.out: main.o func.o output_input.o all_functions.h
	$(CC) $(CFLAGS) main.o func.o output_input.o all_functions.h -o a.out

main.o: main.cpp
	$(CC) -c $(CFLAGS) -c main.cpp 

func.o: func.cpp 
	$(CC) -c $(CFLAGS) -c func.cpp

output_input.o: output_input.cpp
	  $(CC) -c $(CFLAGS) -c output_input.cpp


clean:
	rm -f *.o a.out