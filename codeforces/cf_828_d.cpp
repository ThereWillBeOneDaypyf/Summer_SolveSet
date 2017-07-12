#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e5+8;
vector<int>G[N];
vector<pair<int,int> > edge;
int temp[N];
int d = 0;
int root = 0;
void dfs(int u,int fa,int deep)
{
	if(deep >= d)
		root = u,d = deep;
	for(int i = 0;i<G[u].size();i++)
	{
		int v = G[u][i];
		if(v == fa)
			continue;
		dfs(v,u,deep+1);
	}
}
int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		d = 0;
		for(int i = 0;i<N;i++)
			G[i].clear();
		int cnt = 1;
		n --;
		for(int i = 0;i<m;i++)
			temp[i] = 1;
		while(n > 0)
		{
			for(int i = 0;i<m;i++)
			{
				n -- ;
				edge.push_back(make_pair(temp[i],++cnt));
				G[temp[i]].push_back(cnt);
				G[cnt].push_back(temp[i]);
				temp[i] = cnt;
				if(n == 0)
					break;
			}
		}
		dfs(1,1,0);
		dfs(root,root,0);
		cout << d << endl;
		for(int i = 0;i<edge.size();i++)
			cout << edge[i].first << " " << edge[i].second << endl;
	}
}
