CC = g++ -O3 -Wall -Wextra -pedantic -std=c++0x
LIBS = -lSDL

SRC = ./src/
OBJ = ./obj/

all: raycaster_flat

raycaster_flat: $(OBJ)quickcg.o $(OBJ)raycaster_flat.o
	$(CC) -o raycaster_flat $(OBJ)quickcg.o $(OBJ)raycaster_flat.o $(LIBS)

$(OBJ)quickcg.o: $(SRC)quickcg.cpp $(SRC)quickcg.h
	$(CC) -c -o $(OBJ)quickcg.o $(SRC)quickcg.cpp

$(OBJ)raycaster_flat.o: $(SRC)raycaster_flat.cpp
	$(CC) -c -o $(OBJ)raycaster_flat.o $(SRC)raycaster_flat.cpp

clean:
	rm -rf $(OBJ)*.o raycaster_flat
