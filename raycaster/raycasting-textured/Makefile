CC = g++ -O3 -Wall -Wextra -pedantic -std=c++0x
LIBS = -lSDL

SRC = ./src/
OBJ = ./obj/

all: raycaster_textured

raycaster_textured: $(OBJ)quickcg.o $(OBJ)raycaster_textured.o
	$(CC) -o raycaster_textured $(OBJ)quickcg.o $(OBJ)raycaster_textured.o $(LIBS)

$(OBJ)quickcg.o: $(SRC)quickcg.cpp $(SRC)quickcg.h
	$(CC) -c -o $(OBJ)quickcg.o $(SRC)quickcg.cpp

$(OBJ)raycaster_textured.o: $(SRC)raycaster_textured.cpp
	$(CC) -c -o $(OBJ)raycaster_textured.o $(SRC)raycaster_textured.cpp

clean:
	rm -rf $(OBJ)*.o raycaster_textured
