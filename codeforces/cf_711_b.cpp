#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thansk to qhl ...

long long Map[1000][1000];
long long sum;
int n;
bool judge()
{
	long long ret1 = 0;
	long long ret2 = 0;
	for(int i = 1;i<=n;i++)
	{
		ret1 = 0,ret2 = 0;
		for(int j = 1;j<=n;j++)
		{
			ret1 += Map[i][j];
			ret2 += Map[j][i];
		}
		if(ret1 != sum || ret2 != sum)
			return false;
	}
	ret1 = 0,ret2 = 0;
	for(int i = 1;i<=n;i++)
	{
		ret1 += Map[i][i];
		ret2 += Map[i][n-i+1];
	}
	if(ret1 != sum || ret2 != sum)
		return false;
	else
		return true;
}
int main()
{
	while(cin >> n)
	{
		int x,y;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				cin >> Map[i][j];
				if(!Map[i][j])
					x = i , y = j;
			}
		}
		if(n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		int row = 1;
		while(row == x)
			row ++;
		long long ret = 0;
		sum = 0;
		for(int i = 1; i<= n;i++)
			sum += Map[row][i],ret += Map[x][i];
		Map[x][y] = sum -ret;
		if(Map[x][y]> 0 && judge())
			cout << Map[x][y] << endl;
		else
			cout << -1 << endl;
	}
}
