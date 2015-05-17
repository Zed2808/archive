CC = g++
CFLAGS = -Wall -c
DFLAGS =
OBJS = stuff.o morestuff.o test.o
EXECUTABLE = test

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

stuff.o: stuff.h stuff.cpp
	$(CC) $(CFLAGS) stuff.cpp

morestuff.o: morestuff.h morestuff.cpp
	$(CC) $(CFLAGS) morestuff.cpp

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

clean:
	rm -rf $(OBJS) $(EXECUTABLE)
