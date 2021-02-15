all : runcodes2

run: runcodes2
	./runcodes2

runcodes2 : runcodes2.o pilha_generica.o
	gcc -o runcodes2 runcodes2.o pilha_generica.o
runcodes2.o : runcodes2.c pilha_generica.h
	gcc -c runcodes2.c
pilha_generica.o : pilha_generica.c pilha_generica.h
	gcc -c pilha_generica.c
clean:
	rm *.o runcodes2	