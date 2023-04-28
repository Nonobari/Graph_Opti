all: main

main: main.o graph.o algo.o queue.o
	gcc -o main main.o graph.o algo.o

main.o: main.c graph.h
	gcc -c main.c

graph.o: graph.c graph.h
	gcc -c graph.c

algo.o: algo.c algo.h queue.h
	gcc -c algo.c

queue.o: queue.c queue.h
	gcc -c queue.c

clean:
	rm -f main *.o
