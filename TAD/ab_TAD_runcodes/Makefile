all : main

run : main
	./main # / para linux \ para windows #

main : main.o ab.o
	gcc -o main main.o ab.o
main.o : main.c ab.h
	gcc -c main.c
skiplist.o : ab.c ab.h
	gcc -c ab.c
clean:
	rm *.o main