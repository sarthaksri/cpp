#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int vertex, int color, vector<vector<int>> &g, vector<int> &colors)
{
    for(int neighbor : g[vertex])
    {
        if(colors[neighbor] == color)
        return false;
    }
    return true;
}

bool colorGraph(int vertex, int m, vector<vector<int>> &g, vector<int> &colors)
{
    if(vertex == g.size())
    return true;
    
    for(int color = 1; color <= m; color++)
    {
        if(isSafe(vertex, color, g, colors))
        {
            colors[vertex] = color;
            
            if(colorGraph(vertex+1, m, g, colors))
            return true;
            
            colors[vertex] = 0;
        }
    }
    
    return false;
}

void graphColoring(vector<vector<int>> &g, int m)
{
    int v = g.size();
    vector<int> colors(v, 0);
    
    if(colorGraph(0, m, g, colors))
    {
        cout<<"The graph can be colored in at most " <<m<< " ways as follwing: "<<endl;
        for(int i = 0; i < v; i++)
        {
            cout<<"vertex "<<i<<" : "<<colors[i]<<endl;
        }
    }
    else
    cout<<"Not possible to color the graph with "<<m<<" colors";
}

int main()
{
    vector<vector<int>> adList = {
        {1, 2, 3},    // vertex 0
        {0, 2},  
        {0, 1, 3},  
        {0, 2}     
    };
    
    int m = 3;
    
    graphColoring(adList, m);
}