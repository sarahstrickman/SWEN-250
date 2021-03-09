# Makefile for bubble_sort
# Sarah Strickman sxs4599


HEADERS = bubble_sort.c unit_tests.c

default: test

test: bubble_sort.c 
	gcc -o test -g -Wall bubble_sort.c unit_tests.c
	./test

bubble_sort: bubble_sort.c 
	gcc -o -Wall bubble bubble_sort.c
	./bubble


clean:
	rm test
	rm bubble
