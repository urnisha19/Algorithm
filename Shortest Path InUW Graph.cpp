#include <bits/stdc++.h>

using namespace std;
void bfs(int src, int totNode, vector<int> adjList[])
{
    queue<int> q;
    vector<int> dist(totNode+1, INT_MAX);
    vector<bool> vis(totNode+1, false);
    vector<int> par(totNode+1, 0);

    q.push(src);
    vis[src] = true;
    dist[src] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<(int)adjList[u].size(); i++)
        {
            int v = adjList[u][i];

            if( !vis[v] )
            {
                q.push(v);
                vis[v] = true;
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
        }
    }
    cout << "From the source " << src << " :" << endl;
    for(int i=0; i<totNode; i++)
    {
        if(i==src)
        {
            continue;
        }
        if(dist[i] != INT_MAX)
        {
            cout << "\nMinimum " << dist[ i ] << " edges needed to reach " << i << endl;

            stack<int> stk;
            int cur = i;
            stk.push(cur);
            while(cur!= src)
            {
                cur = par[cur];
                stk.push(cur);
            }
            cout << "Path taken: ";
            while( !stk.empty() )
            {
                int u = stk.top();
                stk.pop();
                cout << u << " ";
            }
            cout << endl;
        }
        else
        {
            cout <<"\n"<< i << " is not reachable" << endl;
        }
    }
}

int main()
{
    int n, m; // total number of nodes (n)  and the total number of edges (m)
    cin >> n >> m;
    vector<int> adjList[n+2];
    for(int i=0; i<m; i++) // m lines will be followed by m pairs of integers denoting the bi-directional edges
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b); //there is a connection from a to b and
        adjList[b].push_back(a); //Also, a connection from b to a.
    }

    int s;
    cin >> s;
    bfs(s, n, adjList);
    return 0;
}


