#include <iostream>
#include <list>
#include <stdlib.h>
using namespace std;
list <long long int> visitedmums;
long long int c=0;
class Graph
{
    long long int V;
	list<long long int> *adj;
	void DFSUtil(long long int v, bool visited[],long long int museums[],long long int a)
    {
        visited[v] = true;
        c+=museums[v];
        list<long long int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if(!visited[*i])
            {
                DFSUtil(*i, visited,museums,c);
            }
        }
    }
public:
	Graph(long long int V)
    {
        this->V = V;
        adj = new list<long long int>[V];
    }
	void addEdge(long long int v, long long int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
	void connectedComponents(long long int museums[])
    {
        bool *visited = new bool[V];
        for(long long int v = 0; v < V; v++)
        {
            visited[v] = false;
        }
        for (int v=0; v<V; v++)
        {
            if (visited[v] == false)
            {
                DFSUtil(v, visited,museums,c);
                visitedmums.push_back(c);
                c=0;
            }
        }
    }
};

int main()
{
    long long int n,m,k,i,x,y;
    long long int tmsum=0,tvm=0;
    cin>>n>>m>>k;
    Graph g(n);
    long long int museums[n];
    for(i=0;i<m;i++)
    {
        cin>>x >>y;
        g.addEdge((x-1),(y-1));
    }
    for(i=0;i<n;i++)
    {
        cin>>museums[i];
        tmsum+=museums[i];
    }
    g.connectedComponents(museums);
    if (visitedmums.size()==k)
    {
        cout<<tmsum;
    }
    else
    {
        if(visitedmums.size()<k)
        {
            cout<<-1;
            exit(0);
        }
        visitedmums.sort();
        for(i=1;i<=k;i++)
        {
            if(i%2!=0)
            {
                tvm+=visitedmums.back();
                visitedmums.pop_back();
            }
            if(i%2==0)
            {
                tvm+=visitedmums.front();
                visitedmums.pop_front();
            }
            if(tvm==tmsum && i<k)
            {
                cout<<-1;
                exit(0);
            }
        }
        cout<<tvm;
    }
    return 0;
}
