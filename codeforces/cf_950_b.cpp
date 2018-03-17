#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		vector<long long> x,y;
		for(int i = 0;i < n;i ++)
		{
			long long temp;
			cin >> temp;
			x.push_back(temp);
		}
		for(int i = 0;i < m;i ++)
		{
			long long temp;
			cin >> temp;
			y.push_back(temp);
		}
		int px = 0,py = 0;
		int ans = 0;
		long long sum_x = 0;
		long long sum_y = 0;
		while(px != n || py != m)
		{
			if(px != n && sum_x < sum_y)
				sum_x += x[px++];
			else if(py != m && sum_x > sum_y)
				sum_y += y[py++];
			else if(sum_x == sum_y)
			{
				ans ++;
				if(px != n)
				{
					sum_x += x[px++];
				}
				else sum_y += y[py ++];
			}
		}
		cout << ans << endl;
	}
}
