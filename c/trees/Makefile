all: test_tree clean

test_tree: binary_tree.o test_tree.o
	gcc -o test_tree test_tree.o binary_tree.o

test_tree.o: test_tree.c
	gcc -c test_tree.c

binary_tree.o: binary_tree.c
	gcc -c binary_tree.c

clean: 
	rm *.o 
