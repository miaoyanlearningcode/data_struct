#include <iostream>

#include "sudoku.h"

using namespace std;

int g[9][9] = 
{
	{6, 0, 3, 0, 2, 0, 0, 9, 0}, 
	{0, 0, 0, 0, 5, 0, 0, 8, 0}, 
	{0, 2, 0, 4, 0, 7, 0, 0, 1},

	{0, 0, 6, 0, 1, 4, 3, 0, 0}, 
	{0, 0, 0, 0, 8, 0, 0, 5, 6}, 
	{0, 4, 0, 6, 0, 3, 2, 0, 0},

	{8, 0, 0, 2, 0, 0, 0, 0, 7}, 
	{0, 1, 0, 0, 7, 5, 8, 0, 0}, 
	{0, 3, 0, 0, 0, 6, 1, 0, 5}
};

int main()
{
	sudoku grid(g);
	grid.printSudokuGrid();

	if (grid.solveSudoku())
		grid.printSudokuGrid();

	return 0;
}