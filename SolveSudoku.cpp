// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9


// } Driver Code Ends

class Solution
{
public:
	//Function to find a solved Sudoku.
	bool isSafe(int grid[N][N], int &row, int &col, int x) {
		for (int k = 0; k < N; k++) {
			if (grid[row][k] == x || grid[k][col] == x) return false;
		}

		int startRow = row - row % 3,
		    startCol = col - col % 3;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (grid[i + startRow][j + startCol] == x)
					return false;
		return true;
	}

	bool SolveSudoku(int grid[N][N])
	{
		int row = 0, col = 0;
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				if (grid[row][col] == 0) {
					for (int x = 1; x <= N; x++) {
						if (isSafe(grid, row, col, x)) {
							grid[row][col] = x;
							if (SolveSudoku(grid)) return true;
							grid[row][col] = 0;
						}
					}
					return false;
				}
			}
		}
		return true;
	}

	//Function to print grids of the Sudoku.
	void printGrid (int grid[N][N])
	{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int grid[N][N];

		Solution ob;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				cin >> grid[i][j];

		ob.printGrid(grid);
		cout << endl << endl;
		if (ob.SolveSudoku(grid) == true)
			ob.printGrid(grid);
		else
			cout << "No solution exists";

		cout << endl;
	}

	return 0;
}  // } Driver Code Ends