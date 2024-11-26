// Place each queen one by one in different rows, starting from the topmost row. While placing a queen
// in a row, check for clashes with already placed queens. For any column, if there is no clash then mark
// this row and column as part of the solution by placing the queen. In case, if no safe cell found due to
// clashes, then backtrack (i.e, undo the placement of recent queen) and return false.

// Enter the number of queens (N): 4
// Q . . .
// . . Q .
// . Q . .
// . . . Q

// Enter the number of queens (N): 5
// Q . . . .
// . . . Q .
// . Q . . .
// . . . . Q
// . . Q . .

#include <iostream>
using namespace std;

#define N 10

void printSolution(int board[N][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[N][N], int row, int col, int n)
{

    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(int board[N][N], int row, int n)
{
    if (row >= n)
        return true;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, n))
                return true;

            board[row][col] = 0;
        }
    }
    return false;
}

void solve(int n)
{
    int board[N][N] = {0};
    if (!solveNQueens(board, 0, n))
    {
        cout << "No solution exists for " << n << " queens.\n";
    }
    else
    {
        printSolution(board, n);
    }
}

int main()
{
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;
    solve(n);
    return 0;
}