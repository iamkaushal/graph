#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<bool> v;
vector<vector<int> > g;

void edge(int a, int b)
{
	g[a].pb(b);
	g[b].pb(a);
}

void dfs(int s)
{
	v[s] = true;	


	cout << s << " " ;
	for(int i=0; i<g[s].size(); i++)
	{
		if(!v[g[s][i]]) 
			dfs(g[s][i]);
	}
}


int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	int n, e;
	cin >> n >> e;

	v.assign(n, false);
	g.assign(n, vector<int>());

	int a, b;
	for(int i=0; i<e; i++)
	{
		cin >> a >> b;
		edge(a, b);
	}

	dfs(0);

	return 0;
}


// sample input 

// 6 14
// 0 1
// 0 4
// 1 0
// 1 3
// 1 4
// 1 2
// 2 1 
// 2 3 
// 3 1
// 3 2
// 3 4
// 4 3
// 4 0
// 4 1