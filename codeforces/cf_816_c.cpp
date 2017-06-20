#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e3 + 5;


int n, m;
int Map[N][N];

void del_row(int row, int val)
{
	for (int i = 0; i < m; i++)
		Map[row][i] --;
}
void del_col(int col, int val)
{
	for (int i = 0; i < n; i++)
		Map[i][col] --;
}
int judge_row(int row)
{
	int Min = INF;
	for (int i = 0; i < m; i++)
		if (!Map[row][i])
			return 0;
		else
			Min = min(Min, Map[row][i]);
	return Min;
}
int judge_col(int col)
{
	int Min = INF;
	for (int i = 0; i < n; i++)
		if (!Map[i][col])
			return 0;
		else
			Min = min(Map[i][col], Min);
	return Min;
}
int main()
{
	while (cin >> n >> m)
	{
		vector<PII>ans;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> Map[i][j];
			}
		}
		int ok = 0;
		for (int i = 0 ; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int flag = 0;
				if (Map[i][j])
				{
					int val;
					while ((val = judge_row(i)))
					{
						flag = 1;
						del_row(i, val);
						ans.push_back(mp(0, i + 1));
					}
					while ((val = judge_col(j)))
					{
						flag = 1;
						del_col(j, val);
						ans.push_back(mp(1, j + 1));
					}
					if (!flag && Map[i][j])
						ok = -1;
				}
			}
		}
		if (ok == -1)
			cout << -1 << endl;
		else
		{
			cout << ans.size() << endl;
			for (int i = 0; i < ans.size(); i++)
			{
				int tar = ans[i].first ;
				int val = ans[i].second;
				if (!tar)
					cout << "row ";
				else
					cout << "col ";
				cout << val << endl;
			}
		}
	}
}