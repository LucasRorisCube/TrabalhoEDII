all: main

run: main
	./main

funcoes.o: funcoes.c
	gcc -o funcoes.o -c funcoes.c

main.o: main.c
	gcc -o main.o -c main.c

main: main.o funcoes.o
	gcc -o main main.o funcoes.o
	
clean:
	@rm *.o