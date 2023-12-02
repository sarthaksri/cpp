#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class graph
{
    public:
    int v;
    list<int> *l;

    // graph(int n)
    // {
    //     v = n;
    //     // l = new list<int>[v];
    // }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(int start)
    {
        vector <bool> visited(v,false);
        queue<int> q;
        
        q.push(start);
        visited[start] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            cout<<node<<" ";

            for(int nbr: l[node])
            {
                if(visited[nbr] == false)
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }   
            }
        }
    }

    void dfs(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout<<node<<" ";

        for(int nbr: l[node])
        {
            if(visited[nbr] == false)
                dfs(nbr , visited);
        }

    }

    void display()
    {
        int i;
        for(i = 0; i<v; i++)
        {
            cout<<"Vertex "<<i<<"->";
            for(int nbr:l[i])
            {
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cout<<"Enter the number of edges: ";
    cin>>n;
    vector <bool> visited(n,false);
    // graph g(n);
    graph g;
    g.addEdge(0,2);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    // g.addEdge(3,5);
    // g.addEdge(4,5);
    g.display();
    g.bfs(0);
    cout<<endl;
    g.dfs(0,visited);
}