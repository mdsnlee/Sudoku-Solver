

typedef struct t_coord
{
    int x;
    int y;
}t_coord;

class SudokuSolver
{
private:
    //save board that was loaded
    int _board[9][9];
    int _solution[9][9];
    int _numSolutions = 0;

public:
    // SudokuSolver(void);
    // SudokuSolver(const SudokuSolver &);
    // ~SudokuSolver(void);

    // SudokuSolver& operator = (const SudokuSolver & moo);

    bool loadBoard(int ac, char**av);
    bool validBoard(t_coord spot, int num);
    bool boardIsFull(void);
    void solve(void);
    void storeSolution(void);
    void printSolution(void);
    void printBoard(void);
    t_coord nextValidSpot(void);
};