#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
vector<int>adjacencyList[10002];
int vis[10002]; //array for marking visited node

void dfs(int u) //dfs called by the current node
{
    vis[u]=1; //marking the current node visited
    cout<< u <<" ";

    for(int i=0; i<(int)adjacencyList[u].size(); i++)
    {
        int v=adjacencyList[u][i]; //v are the neighbor nodes of u
        if(vis[v] == -1)
        {
            dfs(v); //if neighbor nodes are unvisited then again call the dfs with neighbor nodes
        }
    }
    return;
}
int main()
{
    int n, m;
    cin >> n >> m; //taking nodes and edges as input

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    int s;
    cin >> s; //taking the source
    cout<<endl;

    memset(vis, -1, sizeof(vis)); //initially memset filling all nodes as unvisited(-1)
    dfs(s);
    cout<<endl;
    return 0;
}
