#include<bits/stdc++.h>
using namespace std;
#define V 4
void printColor(int *color)
{
    for(int i=0;i<V;i++)
        cout<<color[i]<<" ";
}
int isSafe(int v, bool graph[V][V], int* color, int c)
{
    for(int i=0;i<c;i++)
        if(graph[v][i] && color[i]==c)
            return 0;
    return 1;
}
int util(bool graph[V][V], int m , int *color, int v)
{
    if(v == V)
        return 1;
    for(int c=1;c<=m;c++)
    {
        if(isSafe(v,graph,color,c))
        {
            color[v]=c;
            if(util(graph,m,color,v+1))
                return 1;
            color[v] = 0;
        }
    }
    return 0;
}
int graphColoring(bool graph[V][V], int m)
{
    int *color = (int*)malloc(sizeof(int)*V);
    for(int i=0;i<V;i++)
        color[i] = 0;
    if(!util(graph,m,color,0))
    {
        cout<<"No solution possible.";
        return 0;
    }
    printColor(color);
    return 1;
}
int main()
{
    bool graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; // Number of colors
    graphColoring (graph, m);
    return 0;
}
