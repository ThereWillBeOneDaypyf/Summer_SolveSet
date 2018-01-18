#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int vis[1000000];
void dfs(int pos,int sum)
{
	if(pos >= v.size())
	{
		vis[sum] = 1;
		return;
	}
	dfs(pos + 1,sum + v[pos]);
	dfs(pos + 1,sum);
}
int main()
{
	int n;
	while(cin >> n)
	{
		if(n == 0)
			break;
		v.clear();
		for(int i = 0 ;i < n;i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		memset(vis,0,sizeof(vis));
		dfs(0,0);
		int i;
		for(i = 0;i < 100000;i++)
			if(!vis[i])
				break;
		cout<< i << endl;
	}
}
