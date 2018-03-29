#include<bits/stdc++.h>
using namespace std;
#define size 8
int isSafe(int chessboard[size][size], int curX, int curY)
{
    return(chessboard[curX][curY] == -1 && curX >=0 && curY >=0 && curX < size && curY < size);
}
int util(int chessboard[size][size], int curX, int curY, int moveNo, int *moveX, int *moveY)
{
    if(moveNo == size*size)
        return 1;
    int nextX, nextY;
    for(int k=0;k<8;k++)
    {
        nextX = curX + moveX[k];
        nextY = curY + moveY[k];
        if(isSafe(chessboard,nextX,nextY))
        {
            chessboard[nextX][nextY] = moveNo;
            if(util(chessboard, nextX, nextY, moveNo+1, moveX, moveY))
                return 1;
            else
                chessboard[nextX][nextY] = -1;
        }

    }
    return 0;
}
void printSolution(int sol[size][size])
{
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}
int solveKnightTour(int chessboard[size][size])
{
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            chessboard[i][j]=-1;
    int moveX[] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int moveY[] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    chessboard[0][0] = 0;
    if(!util(chessboard,0,0,1,moveX,moveY))
    {
        cout<<"Solution does not exist.";
        return 0;
    }
    else
        printSolution(chessboard);
    return 1;
}
int main()
{
    int chessboard[size][size];
    solveKnightTour(chessboard);
    return 0;
}
