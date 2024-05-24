test.exe: main.c queue.h queue.o
	gcc -std=c99 -o test.exe main.c queue.o

queue.o: queue.c queue.h
	gcc -c -std=c99 queue.c