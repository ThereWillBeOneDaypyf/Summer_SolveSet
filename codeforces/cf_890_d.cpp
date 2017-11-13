#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int Map[30][30];
int deg[30];
int vis[30];
int fa[30];
string ans;
string cur;
int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int u, int v)
{
	u = find(u), v = find(v);
	fa[u] = v;
}
bool dfs(int u)
{
	cur.push_back((char)('a' + u));
	int cnt = 0;
	int flag = 1;
	for (int i = 0; i < 26; i++)
	{
		if (Map[u][i])
		{
			if (find(u) == find(i))
				return false;
			else
			{
				merge(u, i);
				cnt ++ ;
				flag &= dfs(i);
			}
		}
	}
	return (cnt <= 1 && flag);
}
bool topu()
{
	set<string>s;
	for (int i = 0; i < 30; i++)
	{
		if (deg[i] > 1)
			return false;
		fa[i] = i;
	}
	for (int i = 0; i < 26; i++)
	{
		if (vis[i] && !deg[i])
		{
			cur = "";
			if (dfs(i) && !cur.empty())
				s.insert(cur);
			else
				return false;
		}
	}
	if (s.empty())
		return false;
	else
	{
		ans = "";
		for (auto temp : s)
			ans += temp;
		for (auto op : ans)
			vis[op - 'a'] = 0;
		for (int i = 0; i < 26; i++)
			if (vis[i])
				return false;
		return true;
	}
}
int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		memset(Map, 0, sizeof(Map));
		memset(deg, 0, sizeof(deg));
		memset(vis, 0, sizeof(vis));
		for (int i = 0 ; i < n; i++)
		{
			string s;
			cin >> s;
			vis[s[0] - 'a'] = 1;
			for (int i = 0; i < s.length() - 1; i++)
			{
				int u = s[i] - 'a';
				int v = s[i + 1] - 'a';
				if (!Map[u][v])
					deg[v] ++ ;
				Map[u][v] = 1;
				vis[u] = vis[v] = 1;
			}
		}
		if (topu())
			cout << ans << endl;
		else
			cout << "NO" << endl;
	}
}