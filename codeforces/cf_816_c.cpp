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
struct Node
{
	int flag, cnt, pos;
	Node(int f, int c, int p) : flag(f) , cnt(c) , pos(p) {}
};
void del_row(int row, int val)
{
	for (int i = 0; i < m; i++)
		Map[row][i] -= val;
}
void del_col(int col, int val)
{
	for (int i = 0; i < n; i++)
		Map[i][col] -= val;
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
		vector<Node>ans;
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
				if (Map[i][j] && ok != -1)
				{
					int val;
					while (Map[i][j])
					{
						int val_row = judge_row(i);
						int val_col = judge_col(j);
						if (!val_col && !val_row && Map[i][j])
						{
							ok = -1;
							break;
						}
						else if (val_col > val_row && val_row != 0)
						{
							flag = 1;
							int temp = Map[i][j];
							del_row(i, val_row);
							ans.push_back(Node(0, val_row, i + 1));
						}
						else if (val_row > val_col && val_col != 0)
						{
							flag = 1;
							int temp = Map[i][j];
							del_col(j, val_col);
							ans.push_back(Node(1, val_col, j + 1));
						}
						else if (val_col != 0)
						{
							del_col(j, val_col);
							ans.push_back(Node(1, val_col, j + 1));
						}
						else
						{
							del_row(i, val_row);
							ans.push_back(Node(0, val_row, i + 1));
						}
						// for (int i = 0 ; i < n; i++)
						// {
						// 	for (int j = 0; j < m; j++)
						// 	{
						// 		cout << Map[i][j] << " ";
						// 	}
						// 	cout << endl;
						// }
						// cout << endl;
					}
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
				int tar = ans[i].flag ;
				int val = ans[i].pos;
				for (int i = 0 ; i < ans[i].cnt; i++)
				{
					if (!tar)
						cout << "row ";
					else
						cout << "col ";
					cout << val << endl;
				}

			}
		}
	}
}