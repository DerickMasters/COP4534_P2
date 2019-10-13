# compiler
CC = g++

# compiler flags
CFLAGS = -std=c++11 -g -Wall

OBJECTS = customer.o event.o fifoqueue.o pqueue.o 
HEADERS := $(shell find ./  -name "*.hpp")

main: main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS) : $(HEADERS)
	$(CC) $(CFLAGS) customer.cpp -c -o customer.o
	$(CC) $(CFLAGS) event.cpp -c -o event.o
	$(CC) $(CFLAGS) fifoqueue.cpp -c -o fifoqueue.o
	$(CC) $(CFLAGS) pqueue.cpp -c -o pqueue.o

main.o :
	$(CC) $(CFLAGS) main.cpp -c -o main.o
main: $(OBJECTS) main.o
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	$(RM) *.o *.gch core main 
