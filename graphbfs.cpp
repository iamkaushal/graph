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

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	v[s] = true;

	while(!q.empty())
	{
		int f;
		f = q.front();
		q.pop();
		
		cout << f << " " ;

		for(int i=0; i<g[f].size(); i++)
		{
			if(!v[g[f][i]]) 
			{
				v[g[f][i]] = true;
				q.push(g[f][i]);
			}
		}
	}
}

int main()
{	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,e;
	cin >> n >> e;

	g.assign(n, vector<int> ());
	v.assign(n, false);

	int a,b;
	for(int i=0; i<e; i++)
	{
		cin >> a >> b;
		edge(a, b);
	}

	bfs(0);


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