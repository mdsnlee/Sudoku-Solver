
NAME = SudokuSolver

SRC = src/main.cpp src/SudokuSolver.cpp

INC = -I inc


CC = g++

all: $(NAME)

$(NAME):
	$(CC) $(INC) -o $(NAME) $(SRC)

clean: 
	printf "Nothing to clean"

fclean: clean
	rm SudokuSolver

re: fclean all

test:
	./SudokuSolver "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......."
