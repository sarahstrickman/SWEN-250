HEADERS = main.o read_data.o

default: test_pointers

read_data.o: read_data.c read_data.h $(HEADERS)
	gcc -c -g -Wall read_data.c

main.o: main.c $(HEADERS)
	gcc -c -g -Wall main.c

clean:
	-rm -f *.o
