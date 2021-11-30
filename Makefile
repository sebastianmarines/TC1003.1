OBJS	= main.o
SOURCE	= src/main.cpp
HEADER	= src/Tienda.hpp src/Persona.hpp src/Producto.hpp
OUT	= ric.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: src/main.cpp src/Persona.hpp src/Producto.hpp src/Tienda.hpp
	$(CC) $(FLAGS) src/main.cpp

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OBJS) $(OUT) src/main


.PHONY: all run clean execute