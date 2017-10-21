#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while(cin >> n)
	{
		char x;
		int y;
		int ans = 0;
		int cur = 0;
		for(int i = 0;i<n;i++)
		{
			cin >> x;
			if(x != 'S')
			{
				cin >> y;
				if(y == 1)
				{
		//			ans += cur / 300;
					ans ++;
					cur = 0;
				}
				if(x == 'B')
					cur += 100;
			}
			else
			{
				ans ++;
				cur = 0;
			}
		}
		//ans += cur / 300;
		cout << ans << endl;
	}
}
