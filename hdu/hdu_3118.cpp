#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

int Map[100][100];
int clr[100];
int del[100];
int n;

int solve(int status)
{
	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if((status&(1 << i)) && (status&(1 << j)))
				ans += Map[i][j];
			else if(((status&(1 << i))==0) && ((status&(1 << j))==0))
				ans += Map[i][j];
		}
	}
	return ans/2;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int m;
		cin >> n >> m;
		memset(Map,0,sizeof(Map));
		for(int i = 0;i<m;i++)
		{
			int u,v;
			cin >> u >> v;
			Map[u][v] ++,Map[v][u] ++;
		}
		if(n == 0 || m == 0)
		{
			cout << 0 << endl;
			continue;
		}
		int Min = 0x3f3f3f3f;
		for(int i = 0;i < (1<<n);i++)
		{
			int res = solve(i);
			Min = min(Min,res);
		}
		cout << Min << endl;
	}
}
