#include<bits/stdc++.h>

using namespace std;
int parent[1000];
void sssp_dijkstra(int src, int total, vector<pair<int,int>>adj[])
{
    vector<int>dist(total+1,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push(make_pair(0,src));
    parent[src]=-1;
    dist[src]=0;

    while(!pq.empty())
    {
        pair<int, int>curnode= pq.top();
        pq.pop();

        int a=curnode.second;
        int n_da=curnode.first;

        if(n_da>dist[a])
        {
            continue;
        }
        int sz=adj[a].size();
        for(int i=0; i<sz; i++)
        {
            int b=adj[a][i].first;
            int w_ab=adj[a][i].second;

            if(dist[a]+w_ab<dist[b])
            {
                dist[b]=dist[a]+w_ab;
                parent[b]=a;
                pq.push(make_pair(dist[b],b));
            }
        }
    }
    for(int i=1; i<=total; i++)
    {
        if(dist[i]!=0)
        {
            cout<<i<<" "<<dist[i]<<endl;
        }
    }
    cout<<endl;
}

void path_taken(int source,int node)
{

    if(node==source)
    {
        cout<<node<<" ";
        return ;
    }
    path_taken(source,parent[node]);
    cout<<node<<" ";
}

int main ()
{
    int n, m; //total number of nodes (n)  and the total number of edges (m)
    while(cin>>n>>m)
    {
        vector<pair<int,int>>adjlistwted[n+1];

        for(int i=0; i<m; i++) //m lines followed by m pairs of integers denoting the directed edges.

        {
            int a, b, w;
            cin>>a>>b>>w; //there is a connection from a to b and the cost/distance from a to b is w

            adjlistwted[a].push_back(make_pair(b, w));
        }
        int s,t; //integers s and t denoting the source node and the target node
        cin>>s>>t;
        cout<<"Minimum distances from Source"<<" "<<s<<" "<<"to other nodes"<<endl;
        sssp_dijkstra(s, n, adjlistwted);
        cout<<"Path to the target node"<<": "<<t<<endl;
        cout<<"Path taken"<<": ";
        path_taken(s,t);
        cout<<endl;
    }
    return 0;
}
