#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;


struct edge {
	int frm, to, wt;

	edge(int u, int v, int w) : frm(u), to(v), wt(w) {}

	//~ bool operator < (const edge &e) const
	//~ {
		//~ return w > e.w;
	//~ }
};

int main() {

	freopen("inpWtGraphsEdgeListVid.txt", "r", stdin);

	int n, m, u, v, w;
	/*
	  *
	  * Edge list
	  * with pairs
	  *
	  * weighted but undirected
	  *
	  *
		4 5
		1 2 5
		1 3 7
		1 4 5
		2 4 6
		3 4 8
	  *
	  */

	 vector < pair< int, pair<int, int> > > edgeList;

	 cin >> n >>  m;  // number of edges
	 for(int i=0; i<m; i++) {
		cin >> u >> v >> w;
		edgeList.push_back( make_pair(w, make_pair(u, v)) );

		//
	}

	cout << "Edge List weighted with pairs ( pair< int, pair<int, int> > ) : " << endl;
	for(int i=0; i<(int) edgeList.size(); i++) {
		cout << edgeList[i].second.first << " " << edgeList[i].second.second << "  " << edgeList[i].first << endl;
	}

	/*
	 *
	 * Edge list
	 * with structure
	 *
	 *
	 *
		4 5
		1 2 5
		1 3 7
		1 4 5
		2 4 6
		3 4 8
	 */

	cin >> n >> m;  // number of edges
	vector <edge> edgeListTwo;
	for(int i=0; i<m; i++) {
		cin >> u >> v >> w;
		//~ cout <<  u << " " << " " << v << " " <<  w << endl;
		edgeListTwo.push_back( edge(u, v, w ) );
	}

	cout << "\n Edge List weighted with edge structure (v2) : " << endl;
	for(int i=0; i< (int) edgeListTwo.size(); i++) {
		cout << edgeListTwo[i].frm << " " << edgeListTwo[i].to << " " << edgeListTwo[i].wt << endl;
	}
}
