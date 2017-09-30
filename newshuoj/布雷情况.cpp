#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e3;

int Map[N][N];
int xdir[4] = { 0,1,0,-1 };
int ydir[4] = { 1,0,-1,0 };
int sum[N][N];

int main()
{
	int ka = 0;
	string s;
	while (getline(cin, s))
	{
		memset(sum, 0, sizeof(sum));
		memset(Map, 0, sizeof(Map));
		int row = 1;
		int col = s.length();
		stringstream ss;
		s >> ss;
		int x;
		int cur_col = 1;
		while (ss >> x)
			Map[row][cur_col++] = x;
		while (getline(cin, s))
		{
			if (s.empty())
				break;
			row++;
			s >> ss;
			cur_col = 1;
			while (ss >> x)
				Map[row][cur_col++] = x;
		}
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++)
				sum[i][j] = Map[i][j];
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++)
				for (int k = 0; k < 4; k++)
					sum[i][j] += Map[i + xdir[k]][j + ydir[k]];
		cout << "Case " << ++ka << ":" << endl;
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (j != 1)
					cout << " ";
				cout << sum[i][j];
			}
			cout << endl;
		}
	}
}