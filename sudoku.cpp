#include<bits/stdc++.h>
using namespace std;
#define N 9

int findAssignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return 1;
    return 0;
}
int inRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}
int inCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}
int inBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for(int row = 0; row<3;row++)
    {
        for(int col = 0; col <3; col++)
        if(grid[boxStartRow+row][boxStartCol+col] == num)
            return 1;
    }
    return 0;
}

int isSafe(int grid[N][N], int row, int col, int num)
{

    return !inRow(grid, row, num) &&
           !inCol(grid, col, num) &&
           !inBox(grid, row - row%3 , col - col%3, num);
}
void printGrid(int grid[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<grid[i][j]<<" ";
        cout<<"\n";
    }
}
int solveSudoku(int grid[N][N])
{
    int row, col;

    if (!findAssignedLocation(grid, row, col))
       return 1;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid))
            {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}
int main()
{
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    solveSudoku(grid);
    printGrid(grid);
}
