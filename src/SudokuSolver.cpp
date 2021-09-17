#include <cstring>
#include <iostream>

#include "SudokuSolver.hpp"

//macro
#define NOT_VALID(x) !(x == '.' || (x >= '1' && x <= '9'))

bool SudokuSolver::loadBoard(int ac, char **av)
{
    //check argument count
    if (ac != 10)
        return false; // each argument is 9 long
    for (int i = 1; i <= 9; i++)
    {
        if (strlen(av[i]) != 9)
            return false;
        //if there is an invalid character, return false
        for (int k = 0; k < 9; k++)
        {
            if (NOT_VALID(av[i][k]))
                return false;
            if (av[i][k] == '.')
                _board[i - 1][k] = 0;
            else
                _board[i - 1][k] = av[i][k] - '0';
        }
    }
    return true;
}

t_coord SudokuSolver::nextValidSpot(void)
{
    // t_coord result;
    // result.x = -1;
    // result.y = -1;
    //current -> _board[spot.y][spot.x]
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (_board[y][x] == 0)
            {
               return ((t_coord){x , y});
            }
        }
    }
    return ((t_coord){-1 , -1});
}

// bool SudokuSolver::validBoard(t_coord spot, int num)
// {
//     //check row
//     for(int y = 0; y < 9; y++)
//     {
//         uint8_t table[10] = {0};
//         for(int x = 0; x < 9; x++)
//         {
//             table[_board[y][x]]++;
//             if(table[_board[y][x]] > 1)
//                 {
//                     return false;
//                 }
//         }
//     }

//     //check col
//     for(int x = 0; x < 9; x++)
//     {
//         uint8_t table[10] = {0};
//         for(int y = 0; y < 9; y++)
//         {
//             table[_board[y][x]]++;
//             if(table[_board[y][x]] > 1)
//                 {
//                     return false;
//                 }
//         }
//     }

//     //check box
    
// }

bool SudokuSolver::validBoard(t_coord spot, int num)
{
    //check each row for dupes
    //check each col for dupes
    for (int i = 0; i < 9; i++)
    {
        if (_board[i][spot.x] == num || _board[spot.y][i] == num)
            return false;
    }
    //check each box for dupes

    int row = spot.y / 3;
    int col = spot.x / 3;

    for (int i = row * 3; i < row * 3 + 3; i++)
    {
        for (int k = col * 3; k < col * 3 + 3; k++)
        {
            if(_board[i][k] == num)
                return false;
        }
    }
    return true;
}

bool SudokuSolver::boardIsFull(void)
{
    for (int i = 0; i < 9; i++)
    {
        for (int k = 0; k < 9; k++)
        {
            if (_board[i][k] == 0)
                return false;
        }
    }
    return true;
}

void SudokuSolver::storeSolution(void)
{
    for (int i = 0; i < 9; i++)
        for (int k = 0; k < 9; k++)
            _solution[i][k] = _board[i][k];
    _numSolutions++;
    return;
}

void SudokuSolver::solve(void)
{
    t_coord next_valid = nextValidSpot(); // call this in main
    //find next valid spot
	//loop input number 1 -> 9
    if (next_valid.x == -1)
       return;
        
    for (int i = 1; i <= 9; i++)
    {
		//place number on board
        
		//if valid,
    
        if (validBoard(next_valid, i))
        {
			//check if board is full (store solution)
            _board[next_valid.y][next_valid.x] = i;
            if (boardIsFull())
                storeSolution();
            else
			    //recur with next spot -> solve(x, y)
                solve();
            _board[next_valid.y][next_valid.x] = 0;
        }
		//remove number from board
        
    }
    return;
}

void SudokuSolver::printBoard(void)
{
    for (int i = 0; i< 9 ; i++)
    {
        for (int k = 0; k < 9; k ++)
            std::cout << _board[i][k] << " ";
        std::cout << "\n";
    }
}

void SudokuSolver::printSolution(void)
{
    if(_numSolutions != 1)
    {
        std::cout << "invalid board" << std::endl;
        std::cout << "found " << _numSolutions << " solutions" << std::endl;
        return ;
    }
    for (int i = 0; i< 9 ; i++)
    {
        for (int k = 0; k < 9; k ++)
            std::cout << _solution[i][k] << " ";
        std::cout << "\n";
    }
}
