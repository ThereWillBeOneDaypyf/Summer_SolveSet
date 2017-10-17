#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N = 1e3 + 7;
int n, m;
int dp[N][N][4];
char Map[N][N];
int xdir[4] = {0, 1, 0, -1};
int ydir[4] = {1, 0, -1, 0};
map<char, int>dir;
void init()
{
	dir.clear();
	dir['E'] = 0;
	dir['S'] = 1;
	dir['W'] = 2;
	dir['N'] = 3;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j][0] = dp[i][j - 1][0];
			dp[i][j][1] = dp[i - 1][j][1];
			if (Map[i][j] == '#')
			{
				dp[i][j][0] ++;
				dp[i][j][1] ++;
			}
		}
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = m; j > 0; j--)
		{
			dp[i][j][2] = dp[i][j + 1][2];
			dp[i][j][3] = dp[i + 1][j][3];
			if (Map[i][j] == '#')
			{
				dp[i][j][2] ++;
				dp[i][j][3] ++;
			}
		}
	}
}
void debug()
{
	for (int k = 0; k < 4; k++)
	{
		cout << "***" << k << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				cout << dp[i][j][k] << " ";
			cout << endl;
		}
	}
}
struct Node
{
	int x, y;
	char cap;
};
bool judge(Node & x, char Dir, int dis)
{
	int tx = x.x + xdir[dir[Dir]] * dis;
	int ty = x.y + ydir[dir[Dir]] * dis;
	if (tx < 1 || tx > n || ty < 1 || ty > m)
		return false;
	if (- dp[x.x][x.y][dir[Dir]] + dp[tx][ty][dir[Dir]] > 0)
		return false;
	x.x = tx, x.y = ty;
	return true;
}
int main()
{
	while (scanf("%d%d", &n, &m) == 2)
	{
		queue<Node>q[2];
		for (int i = 1; i <= n; i++)
		{
			char s[N];
			scanf("%s", s);
			for (int j = 1; j <= m; j++)
			{
				Map[i][j] = s[j];
				if (isalpha(Map[i][j]))
				{
					q[0].push({i, j, Map[i][j]});
				}
			}
		}
		init();
		//debug();
		int k;
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
		{
			char op[5];
			int dis;
			scanf("%s%d", op, &dis);
			while (!q[i % 2].empty())
			{
				auto temp = q[i % 2].front();
				q[i % 2].pop();
				//cout << "Old " << temp.x << " " << temp.y << " ";
				if (judge(temp, op[0], dis))
				{
					//	cout << "New " << temp.x << " " << temp.y;
					q[(i % 2) ^ 1].push(temp);
				}
				//cout << endl;
			}
		}
		set<char>st;
		while (!q[(k) % 2].empty())
		{
			st.insert(q[(k) % 2].front().cap);
			q[(k) % 2].pop();
		}
		if (st.size() == 0)
		{
			printf("No Solution\n");
			continue;
		}
		for (auto temp : st)
			printf("%c", temp);
		printf("\n");
	}
}
