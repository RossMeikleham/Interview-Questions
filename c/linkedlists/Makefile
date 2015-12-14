CC = gcc

all: test_lists clean

test_lists: test_lists.o single_ll.o
	gcc -o test_lists test_lists.o single_ll.o

test_lists.o: test_lists.c
	gcc -c test_lists.c

single_ll.o: single_ll.c
	gcc -c single_ll.c

clean: 
	rm *.o 
