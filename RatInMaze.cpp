#include<bits/stdc++.h>
using namespace std;
#define size 4
void printPath(int path[size][size])
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            cout<<path[i][j]<<" ";
        cout<<endl;
    }
}
int isSafe(int maze[size][size], int curX, int curY)
{
    return(curX>=0 && curX < size && curY>=0 && curY<size && maze[curX][curY]==1);
}
int util(int maze[size][size], int path[size][size],int curX, int curY)
{
    if(curX == size-1 && curY == size-1)
    {
        path[curX][curY]=1;
        return 1;
    }
    if(isSafe(maze,curX,curY))
    {
        path[curX][curY] = 1;
        if(util(maze,path,curX+1,curY))
            return 1;
        if(util(maze,path,curX,curY+1))
            return 1;
        else
        {
            path[curX][curY] = 0;
            return 0;
        }
    }
    return 0;
}
int ratInMaze(int maze[size][size])
{
    int path[size][size]={0};
    if(!util(maze, path, 0, 0))
    {
        cout<<"No path available.";
        return 0;
    }
    printPath(path);
    return 1;

}
int main()
{
    int maze[size][size]={{1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}};
    ratInMaze(maze);
    return 0;
}
