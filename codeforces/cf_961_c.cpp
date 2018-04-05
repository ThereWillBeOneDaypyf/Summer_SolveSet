#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int Map[N][N];
int st[N][N][4];
int a[4];
int n;

int judge(int start)
{
	int cnt = 0;
	int res[2] = {start, !start};
	for (int i = 0; i < 2 * n; i ++)
		for (int j = 0; j < 2 * n; j ++)
			if (res[(i + j) % 2] != Map[i][j])
				cnt ++;
	return cnt;
}

void f()
{
	int ans = 1e9 + 7;
	do
	{
		memset(Map, 0, sizeof(Map));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j ++)
			{
				Map[i][j] = st[i][j][a[0]];
			}
		}
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				Map[i][j + n] = st[i][j][a[1]];
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				Map[i + n][j] = st[i][j][a[2]];
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				Map[i + n][j + n] = st[i][j][a[3]];
		ans = min(ans, judge(0));
		ans = min(ans, judge(1));
	}
	while (next_permutation(a, a + 4));
	cout << ans << endl;
}

int main()
{
	while (cin >> n)
	{
		for (int k = 0; k < 4; k ++)
		{
			for (int i = 0; i < n; i ++)
			{
				string s;
				cin >> s;
				for (int j = 0; j < n; j ++)
					st[i][j][k] = s[j] - '0';
			}
		}
		for (int i = 0; i < 4; i ++)
			a[i] = i;
		f();
	}
}