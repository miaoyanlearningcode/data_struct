#include <iostream>

using namespace std;

class sudoku
{
public:
	sudoku();

	sudoku(int g[][9]);

	void initializeSudokuGrid();

	void initializeSudokuGrid(int g[][9]);

	void printSudokuGrid();

	bool solveSudoku();

	bool findEmptyGridSlot(int &row, int &col);

	bool canPlaceNum(int row, int col, int num);

	bool numAlreadyInRow(int row, int num);

	bool numAlreadyInCol(int col, int num);

	bool numAlreadyInBox(int smallGridRow, int smallGridCol, int num);

private:
	int grid[9][9];
};

sudoku::sudoku()
{
	initializeSudokuGrid();
}

sudoku::sudoku(int g[][9])
{
	initializeSudokuGrid(g);
}

void sudoku::initializeSudokuGrid()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			grid[i][j] = 0;
		}
	}
}

void sudoku::initializeSudokuGrid(int g[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			grid[i][j] = g[i][j];
		}
	}
}

void sudoku::printSudokuGrid()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool sudoku::solveSudoku()
{
	int row, col;

	if (findEmptyGridSlot(row, col))
	{
		for (int num = 1; num <= 9; num++)
		{
			if (canPlaceNum(row, col, num))
			{
				grid[row][col] = num;

				//printSudokuGrid();

				if (solveSudoku())
					return true;

				grid[row][col] = 0;
			}
		}

		return false;
	}
	else 
		return true;
}

bool sudoku::findEmptyGridSlot(int &row, int &col)
{
	for (row = 0; row < 9; row ++)
	{
		for (col = 0; col < 9; col ++)
		{
			if (grid[row][col] == 0)
				return true;
		}
	}
	return false;
}


bool sudoku::numAlreadyInRow(int row, int num)
{
	bool found = false;
	for (int i = 0; i < 9; i++)
	{
		if (grid[row][i] == num)
		{
			found = true;
			break;
		}
	}
	return found;
}

bool sudoku::numAlreadyInCol(int col, int num)
{
	bool found = false;
	for (int i = 0; i < 9; i++)
	{
		if (grid[i][col] == num)
		{
			found = true;
			break;
		}
	}
	return found; 
}

bool sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, int num)
{
	bool found = false;

	for(int i = 3 * smallGridRow; i < (3 * smallGridRow + 3); i++)
	{
		for(int j = 3 * smallGridCol; j < (3 * smallGridCol + 3); j++)
		{
			found = ((grid[i][j] == num) || (found));
		}
	}
	return found;
}

bool sudoku::canPlaceNum(int row, int col, int num)
{
	if (!numAlreadyInBox(row/3, col/3, num) && !numAlreadyInRow(row, num) && !numAlreadyInCol(col, num))
		return true;
	else
		return false;
}