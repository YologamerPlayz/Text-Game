GPP=g++
INCLUDE=include
LIBS=lib
OUTPUT=output/game
FLAGS=-O3 -Wall
INPUT=src/*.cpp

output: $(INPUT)
	$(GPP) $(INPUT) -I$(INCLUDE) -o $(OUTPUT) -s -L$(LIBS) $(FLAGS) 

run:
	./$(OUTPUT).exe