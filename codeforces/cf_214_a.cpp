#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		int ans = 0;
		for(int i = 0;i<=1000;i++)
		{
			for(int j = 0;j<=1000;j++)
			{
				if(i * i + j == n && i + j * j ==m)
					ans ++;
			}
		}
		cout << ans << endl;
	}
}
