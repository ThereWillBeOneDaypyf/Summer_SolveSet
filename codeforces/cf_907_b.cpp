#include<bits/stdc++.h>
using namespace std;

char Map[12][12];
bool judge(int x, int y)
{
	for (int i = x; i < x + 3; i ++)
		for (int j = y; j < y + 3; j ++)
			if (Map[i][j] == '.')
				return true;
	return false;
}
pair<int, int> find(int x, int y)
{
	x %= 3, y %= 3;
	if (x == 0)
		x = 3;
	if (y == 0)
		y = 3;
	return make_pair((x - 1) * 3 + 1, (y - 1) * 3 + 1);
}
void solve(int x, int y)
{
	int sx, sy;
	pair<int, int> temp = find(x, y);
	if (judge(temp.first, temp.second))
	{
		for (int i = temp.first; i < temp.first + 3; i++)
			for (int j = temp.second; j < temp.second + 3; j++)
				if (Map[i][j] == '.')
					Map[i][j] = '!';
	}
	else
	{
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j ++)
				if (Map[i][j] == '.')
					Map[i][j] = '!';
	}
}
void output()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << Map[i][j];
			if (j % 3 == 0)
			{
				if (j == 9)
					cout << endl;
				else
					cout << ' ';
			}
		}
		if (i % 3 == 0 && i != 9)
			cout << endl;
	}
}
int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> Map[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	solve(x, y);
	output();
}