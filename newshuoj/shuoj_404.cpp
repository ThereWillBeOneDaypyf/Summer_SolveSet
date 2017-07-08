#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 6;

vector<int>G[N];
int Max = 0;
void dfs(int u,int d,int fa)
{
	Max = max(Max,d);
	for(int i =0 ;i<G[u].size();i++)
	{
		int v = G[u][i];
		if(v == fa)
			continue;
		dfs(v,d+1,u);
	}	
}
int main()
{
	int n;
	while(cin >> n )
	{
		Max = 0;
		for(int i =0;i<N;i++)
			G[i].clear();
		for(int i = 1;i<n;i++)
		{
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(0,0,0);
		cout << Max << endl;
	}
}

