#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

void dfs(int source, int totalNode, vector<int>adjacencyList[])
{
    vector<bool>visited(totalNode+1, false); //creating a boolean vector for keeping visited nodes and here false is for initially marking all vertex unexplored/unvisited
    stack<int>stk; //creating an stack

    stk.push(source);
    visited[source]=true;

    while(!stk.empty())
    {
        int u = stk.top(); //initializing the stack's top node with u
        stk.pop();

        cout<< u << " "; //printing the traversal order
        for(int i=0; i<(int)adjacencyList[u].size(); i++)
        {
            int v= adjacencyList[u][i]; //initializing u's neighbor nodes with v
            if(!visited[v]) //if neigbor node is not visited earlier then push it to the stack and mark as visited
            {
                stk.push(v);
                visited[v]=true;
            }
        }
    }
}
int main()
{
    int n, m; //total number of nodes (n) and the total number of edges (m)
    cin >> n >> m;
    vector<int> adjacencyList[n+1];
    for(int i=0; i<m; i++) //m lines followed by m pairs of integers denoting the bi-directional edges
    {
        int u,v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);//adding v in the adjacency list of u
        adjacencyList[v].push_back(u);//adding u in the adjacency list of v
    }
    int s; //a single integer s denoting the source
    cin >> s;
    cout<<"The list of vertices we can go from the source: "<< endl;
    dfs(s, n, adjacencyList);
}
