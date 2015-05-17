CC=gcc
CFLAGS=-Wall
LDFLAGS=-lncurses
SOURCES=makebold.c
OBECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=makebold

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
