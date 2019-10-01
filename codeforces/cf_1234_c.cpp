#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int g[N][3];
int n;

bool dfs(int x, int y, int dir)
{
	if(x > n)
	{
		if(y == 2)
			return true;
		return false;
	}

	if(y < 1 || y > 2)
		return false;
	// cout << x << " " << y << " " << dir << endl;
	if(g[x][y] == 1 || g[x][y] == 2)
	{
		if(dir == 1)
			return false;
		return dfs(x + 1, y, 0);
	}
	else 
	{
		if(dir == 1)
		{
			return dfs(x + 1, y, 0);
		}
		else 
		{
			if(y == 1)
				return dfs(x, y + 1, 1);
			else return dfs(x, y - 1, 1);
		}
	}
}

int main()
{
	int q;
	cin >> q;
	while(q--)
	{
		cin >> n;
		string s1,s2;
		cin >> s1 >> s2;
		for(int i = 0;i < n; i ++)
		{
			g[i + 1][1] = s1[i] - '0';
			g[i + 1][2] = s2[i] - '0';
		}

		if(dfs(1, 1, 0))
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
