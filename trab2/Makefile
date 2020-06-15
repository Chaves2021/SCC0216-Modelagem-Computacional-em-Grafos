CC=gcc
BIN=./bin/main
INCLUDES=./includes/
SRC=./src/graph.c ./src/dyn_list_symple.c ./src/main.c
OPTIONS=-Wall -g -lm
TEST=casos/11.in


all:
	@$(CC) $(SRC) -o $(BIN) -I$(INCLUDES) $(OPTIONS)
run:
	@$(BIN)
debug:
	@$(CC) $(SRC) -o $(BIN) -I$(INCLUDES) $(OPTIONS)
	@valgrind --leak-check=yes $(BIN) < $(TEST)
