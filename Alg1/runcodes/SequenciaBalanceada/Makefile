all: compile
	gcc item.o Pilha.o balanceada.o -o balanceada

compile:
	gcc item.c Pilha.c balanceada.c -c

clean:
	rm *.o balanceada

run:
	./balanceada

remake: clean all