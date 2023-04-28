all: main

main: main.o graph.o
	gcc -o main main.o graph.o

main.o: main.c graph.h
	gcc -c main.c

graph.o: graph.c graph.h
	gcc -c graph.c

clean:
	rm -f main *.o
