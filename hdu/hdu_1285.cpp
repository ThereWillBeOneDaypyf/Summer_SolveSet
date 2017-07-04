#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e4;

vector<int>G[N];
int deg[N];
int ans[N];
int n,m;
void topu()
{
	for(int i = 0;i<n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(!deg[j])
			{
				deg[j] -- ;
				ans[i] = j;
				for(int k = 0;k<G[j].size();k++)
				{
					deg[G[j][k]] --;
				}
				break;
			}
		}	
	}
}
int main()
{
	while(cin >> n >> m)
	{
		memset(deg,0,sizeof(deg));
		for(int i = 0;i<N;i++)
			G[i].clear();
		for(int i = 0;i<m;i++)
		{
			int u,v;
			cin >> u >> v;
			deg[v] ++;
			G[u].push_back(v);
		}
		topu();
		for(int i = 0;i<n;i++)
		{
			if(i)
				cout << " " ;
			cout << ans[i];
		}
		cout << endl;
	}	
}
