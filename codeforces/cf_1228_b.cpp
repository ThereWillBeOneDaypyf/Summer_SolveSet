#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int vis[N][N];
int row[N];
int ban[N][N];
int col[N];
const int MOD = 1e9 + 7;

void init()
{
	memset(vis, 0, sizeof(vis));
	memset(ban, 0, sizeof(ban));
	for(int i = 0; i < N; i ++)
		ban[i][0] = ban[0][i] = 1;
}

bool check(int r, int c)
{
	for(int i = 0; i < r; i ++)
	{
		int cnt = 0;
		for(int j = 0; j < c; j ++)
			if(vis[i][j])
				cnt ++;
			else 
				break;
		if(cnt != row[i])
		// {
		// 	cout << "row :" << i << " "  << endl;
			return false;
		// }
	}

	for(int j = 0; j < c; j++)
	{
		int cnt = 0;
		for(int i = 0; i < r; i ++)
			if(vis[i][j])
				cnt ++;
			else 
				break;
		if(cnt != col[j])
		//{
		//	cout << "col :" <<  " " << j << endl;
			return false;
		//}
	}
	return true;
}

int main()
{
	int r, c;
	while(cin >> r >> c)
	{
		init();
		for(int i = 0;i < r; i ++)
		{
			cin >> row[i];
			for(int j = 0; j < row[i]; j ++)
				vis[i][j] = 1;
			ban[i][row[i]] = 1;

		}
		for(int j = 0; j < c; j++)
		{
			cin >> col[j];
			for(int i = 0; i < col[j]; i ++)
				vis[i][j] = 1;
			ban[col[j]][j] = 1;
		}
		for(int i = 0;i < r; i ++)
		{
			for(int j = 0;j < c; j ++)
				cout << vis[i][j] << " ";
			cout << endl;
		}
		if(!check(r, c))
		{
			cout << 0 << endl;
			continue;
		}

		int cnt = 0;
		for(int i = 1; i < r; i ++)
		{
			for(int j = 1; j < c; j ++)
			{
				if(!vis[i][j] && !ban[i][j])
					cnt ++;
			}
		}
		cout << cnt << endl;
		long long base = 1;
		for(int i = 0; i < cnt; i ++)
		{
			base *= 2;
			base %= MOD;
		}
		cout << base << endl;
	}
}
