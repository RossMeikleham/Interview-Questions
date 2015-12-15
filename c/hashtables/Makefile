CC = gcc

all: hash_tests clean

hash_tests: hash_tests.o seperate_chaining.o linear_probing.o
	gcc -o hash_tests hash_tests.o seperate_chaining.o linear_probing.o

hash_tests.o: hash_tests.c
	gcc -c hash_tests.c

seperate_chaining.o: seperate_chaining.c
	gcc -c seperate_chaining.c

linear_probing.o: linear_probing.c
	gcc -c linear_probing.c

clean: 
	rm *.o 
