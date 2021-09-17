#include <iostream>

#include "SudokuSolver.hpp"

int main(int ac, char **av)
{
	//make sudoku object
	SudokuSolver solver;

	if (solver.loadBoard(ac, av)) //should fail to load if board isnt valid
	{
		solver.solve();
		solver.printSolution();
	}
	
	return 0;
}