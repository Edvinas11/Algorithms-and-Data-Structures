test.exe: main.c loans.h queue.o loans.o priorityQueue.o
	gcc -std=c99 -o test.exe main.c loans.o queue.o priorityQueue.o

loans.o: loans.c loans.h
	gcc -c -std=c99 loans.c

queue.o: queue.c loans.h
	gcc -c -std=c99 queue.c

priorityQueue.o: priorityQueue.c loans.h
	gcc -c -std=c99 priorityQueue.c