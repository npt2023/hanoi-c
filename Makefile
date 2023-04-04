hanoi: hanoi.o stack.o
	gcc -o hanoi hanoi.o stack.o
stack.o: hanoi.h stack.h stack.c
	gcc -c stack.c
hanoi.o: hanoi.h stack.h hanoi.c
	gcc -c hanoi.c
