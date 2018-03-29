#include<bits/stdc++.h>
using namespace std;
#define row 4
#define col 4
int countPaths(int maze[row][col])
{
    if(maze[0][0] == -1)
        return 0;
    for(int i=0;i<row;i++)
       {
            if(maze[i][0] == 0)
                maze[i][0] = 1;
            else
                break;
       }
    for(int i=1;i<col;i++)
    {
        if(maze[0][i] == 0)
            maze[0][i] = 1;
        else
            break;
    }
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(maze[i][j] == -1)
                continue;
            if(maze[i-1][j] > 0)
                maze[i][j] += maze[i-1][j];
            if(maze[i][j-1] >0)
                maze[i][j] += maze[i][j-1];
        }
    }
    return (maze[row-1][col-1]>0)?maze[row-1][col-1]:0;
}
int main()
{
    int maze[row][col] = {{0,  0, 0, 0},
                       {0, -1, 0, 0},
                       {-1, 0, 0, 0},
                       {0,  0, 0, 0}};
    cout<<countPaths(maze)<<" paths.";
}
