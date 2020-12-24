CC = gcc

objects = queue.o functions.o

LinkedList: $(objects)
	$(CC) -o queue $(objects)

queue.o: queue.h

functions.o: queue.h

.PHONY: clean
clean:
	rm $(objects) queue