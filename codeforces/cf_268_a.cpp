#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int h[100];
int g[100];

int main()
{
	int n;
	while(cin >> n)
	{
		for(int i = 0;i<n;i++)
			cin >> h[i] >> g[i];
		int ans = 0;
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
			{
				if(i != j)
				{
					if(h[i] == g[j])
						ans ++;
				}
			}
		}
		cout << ans << endl;
	}
}
