#include<bits/stdc++.h>
using namespace std;
#define size 8
void printBoard(int path[size][size])
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            cout<<path[i][j]<<" ";
        cout<<endl;
    }
}
int isSafe(int board[size][size], int row, int col)
{
    for(int i=0;i<col;i++)
        if(board[row][i])
            return 0;
    for(int i=row,j=col; i>=0 && j>=0; i--,j--)
        if(board[i][j])
            return 0;
    for(int i=row,j=col; i<size && j>=0; i++,j--)
        if(board[i][j])
            return 0;
    return 1;
}
int util(int board[size][size],int col)
{
    if(col >= size)
        return 1;
    for(int i=0; i<size;i++)
    {
        if(isSafe(board, i, col))
        {
            board[i][col] = 1;
            if(util(board, col+1))
                return 1;
            else
                board[i][col] = 0;
        }
    }
    return 0;
}
void nQueen()
{
    int board[size][size] = {0};
    if(util(board, 0))
    {
        printBoard(board);
        return;
    }
    cout<<"Solution not possible.";
    return;
}
int main()
{
    nQueen();
    return 0;
}
