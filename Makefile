all:

	gcc src/main.c src/linkedlist.c -Wall -std=c99 -I include
	./a.out
