#include <iostream>
#include "nQueens.h"

using namespace std;

int main()
{
	nQueensPuzzle queens(8);
	queens.queensConfiguration(0);
	cout << "Solution Number: " << queens.solutionCount() << endl;
	return 0;
}