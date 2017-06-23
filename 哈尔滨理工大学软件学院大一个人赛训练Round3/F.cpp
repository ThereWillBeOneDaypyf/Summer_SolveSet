#include<bits/stdc++.h>
using namespace std;

char ans[80][80][80];


void f()
{
	for(int n = 3 ;n<80;n++)
	{
		for(int i = 0 ;i < n;i++)
		{
			for(int j = 0;j<n;j++)
			{
				if((i+j) == n-1 || i == j)
					ans[i][j][n] = 'X';
				else
					ans[i][j][n] = ' ';
			}
		}
	}
}

int main()
{
	f();
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i =0 ;i<n;i++)
		{
			int cnt = 0;
			for(int j = 0;j<n;j++)
			{
				cout << ans[i][j][n];
				if(ans[i][j][n]=='X')
				{
					cnt ++;
					if(i == j&&i == n/2)
						cnt ++;
				}
				if(cnt == 2)
					break;
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
