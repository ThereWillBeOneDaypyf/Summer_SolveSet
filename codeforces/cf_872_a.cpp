#include<bits/stdc++.h>
using namespace std;

vector<int>v1,v2;

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		v1.clear(),v2.clear();
		for(int i =0;i<n;i++)
		{
			int x;
			cin >> x;
			v1.push_back(x);
		}
		for(int i = 0;i<m;i++)
		{
			int x;
			cin >> x;
			v2.push_back(x);
		}
		int ans = 0;
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		for(auto x1 : v1)
		{
			for(auto x2 : v2)
			{
				if(x1 == x2)
				{
					ans = x1;
					break;
				}
			}
			if(ans)
				break;
		}
		if(ans)
			cout << ans << endl;
		else
		{
			cout << min(v1[0],v2[0]) << max(v1[0],v2[0]) << endl;
		}
	}
}
