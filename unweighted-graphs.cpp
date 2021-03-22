#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{

    freopen("inpUnWtGraphsVid.txt", "r", stdin);
    int n;
    cin >> n; // taking number of nodes;

    bool adjMat[n][n]; //declaring an adjacency matrix
    memset(adjMat, 0, sizeof adjMat); //here memset fuction fills the adjacency matrix with 0(suppose there is no connection between vertices)

    for(int i=1; i<=n; i++)//row
    {
        for(int j=1; j<=n; j++)//column
        {
            int v;
            cin >> v; //taking the vertices to corresponding (row,column)if connected 1 if not connected 0
            adjMat[i][j] = v;
        }
    }
    cout << "Adjacency Matrix unweighted: " << endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
/*
     *
     * Adjacency List
     * Unweighted
     *
     *
     * 4 5
    1 2
    1 3
    1 4
    2 4
    3 4
     *
     * */
    int m;
    cin >> n >> m;  // number of nodes and edges
    vector<int> adjList[n+1];//taking a vector's array
    for(int i=0; i<m; i++) //jotota edge ache totota input nibo
    {
        int u, v;
        cin >> u >> v;//u holo 1st node v holo 2nd node
        adjList[u].push_back(v); //u tomo position er vector er shate v add korlam

        //if bidirectional/ undirected
        adjList[v].push_back(u); //v tomo position er vector er shateo u add korbo jodi bidirected hoy
    }

    cout << "Adjacency List unweighted(undirected) : " << endl;
    for(int i=1; i<=n; i++)
    {
        cout << i << " --> ";
        for(int j=0; j< (int) adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}
