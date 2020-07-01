CC=gcc
BIN=./bin/main
INCLUDES=./includes/
SRC=./src/graph.c ./src/dyn_list_symple.c ./src/main.c
OPTIONS=-Wall -g -lm
TEST=casos/2.in


all:
	@$(CC) $(SRC) -o $(BIN) -I$(INCLUDES) $(OPTIONS)
run:
	@$(BIN) #< $(TEST)
clean:
	rm trab.zip
	rm ./bin/*
zip:
	zip -r trab.zip ./bin $(INCLUDES) ./src Makefile
debug:
	@$(CC) $(SRC) -o $(BIN) -I$(INCLUDES) $(OPTIONS)
	@valgrind --leak-check=yes $(BIN) < $(TEST)
debug2:
	@$(CC) $(OPTIONS) -fsanitize=address $(SRC) -I$(INCLUDES) -o $(BIN)
