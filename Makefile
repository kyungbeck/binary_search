all:
	g++ -o BinarySearch BinarySearch.c
run:
	./BinarySearch
gdb:
	g++ -g -o BinarySearch BinarySearch.c
	gdb BinarySearch
