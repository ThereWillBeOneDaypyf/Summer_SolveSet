#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int k,n;
		cin >> k >> n;
		vector<int> q;
		int ans = 0;
		for(int i = 0;i < n;i ++)
		{
			int x;
			cin >> x;
			bool incache = false;
			for(auto temp : q)
			{
				if(temp == x)
					incache = true;
			}
			if(incache)
			{
				ans ++;
				continue;
			}
			if(q.size() == k)
				q.erase(q.begin());
			q.push_back(x);
		}
		cout << ans <<endl;
	}
}
