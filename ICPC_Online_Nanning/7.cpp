#include<bits/stdc++.h>
using namespace std;

vector<int>v1,v2;
int ans = 0;
int vis[100000];
void dfs(int x)
{
	if(vis[x])
		return;
	vis[x] = 1;
	for(int i = 0;i<v2.size();i++)
	{
		if(v2[i] == v1[x])
		{
			ans ++;
			dfs(i);
			break;
		}
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	string s1,s2;
	int n;
	while(cin >> n)
	{
		int T =5;
		while(T--)
		{
			v1.clear(),v2.clear();
			cin >> s1 >> s2;
			v1.push_back(s1[0] - '0');
			v2.push_back(s2[0] - '0');
			for(int i = 1;i<s1.size();i++)
			{
				if(s1[i] != s2[i])
				{
					v1.push_back(s1[i] - '0');
					v2.push_back(s2[i] - '0');
				}
			}
			int cnt = 0;
			memset(vis,0,sizeof(vis));
			ans = 0;
			dfs(0);
			cnt += (ans - 1);
			for(int i = 0;i<v1.size();i++)
			{
				if(!vis[i])
				{
					ans = 0;
					dfs(i);
					cnt += (ans + 1);
				}
			}
			cout << cnt << endl;
		}
	}
}
