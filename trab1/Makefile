CC=gcc
BIN=./bin/main
INCLUDES=./includes/
SRC=./src/graph.c ./src/main.c
OPTIONS=-Wall -g -lm
TEST=0


all:
	@$(CC) $(SRC) -o $(BIN) -I$(INCLUDES) $(OPTIONS)
run:
	@$(BIN)
debug:
	@$(CC) $(SRC) -o $(BIN) -I$(INCLUDES) $(OPTIONS)
	@valgrind --leak-check=yes $(BIN) < $(TEST)
