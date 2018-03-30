#include<bits/stdc++.h>
using namespace std;
#define V 5
void printPath(int *path)
{
    for(int i=0;i<V;i++)
        cout<<path[i]<<" ";
    cout<<path[0]<<endl;
}
int isSafe(int v, bool graph[V][V], int* path, int pos)
{
    if(graph[path[pos-1]][v] == 0)
        return 0;
    for(int i=0;i<pos;i++)
        if(path[i] == v)
            return 0;
    return 1;
}
int util(bool graph[V][V], int *path, int pos)
{
    if(pos == V)
    {
        if ( graph[ path[pos-1] ][ path[0] ] == 1 )
           return 1;
        else
          return 0;
    }
    for(int v=1;v<V;v++)
    {
        if(isSafe(v,graph,path,pos))
        {
            path[pos] = v;
            if(util(graph, path, pos+1))
                return 1;
            path[pos] = -1;
        }
    }
    return 0;
}
int hamCycle(bool graph[V][V])
{
    int *path = (int*) malloc (sizeof(int)*V);
    for(int i=0;i<V;i++)
        path[i] = -1;
    path[0]=0;
    if(util(graph,path,1))
    {
       printPath(path);
       return 1;
    }
    cout<<"No hamiltonian cycle.";
    return 0;
}
int main()
{
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
    hamCycle(graph1);
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
    hamCycle(graph2);
    return 0;
}
