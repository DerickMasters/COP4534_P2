# compiler
CC = g++

# compiler flags
CFLAGS = -sdt=c++11 -g -Wall

OBJECTS = #add object files
HEADERS := $(shell find ./  -name "*.hpp")

main: main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS) : $(HEADERS)
	$(CC) $(CFLAGS) # add files

clean: $(RM) *.o *.gch core main 
