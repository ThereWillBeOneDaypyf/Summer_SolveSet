#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios :: sync_with_stdio(false);
	int n,t;
	while(cin >> n >> t)
	{
		int cur = 0;
		int flag = 0;
		for(int i = 1;i<=n;i++)
		{
			int x;
			cin >> x;
			cur += (86400 - x);
			if(!flag && cur >= t)
				flag = i;
		}		
		cout << flag << endl;
	}
}
