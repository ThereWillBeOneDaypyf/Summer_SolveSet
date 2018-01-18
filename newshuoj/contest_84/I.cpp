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
		set<pair<int,int> > incache;
		int ans = 0;
		for(int i = 0;i < n;i++)
		{
			int x;
			cin >> x;
			int isin = 0;
			set<pair<int,int> > :: iterator it;
			for(auto temp = incache.begin(); temp != incache.end();
					temp ++)
				if((*temp).second == x)
				{
					isin = 1;
					it = temp;
					break;
				}
			if(isin)
			{
				ans ++;
				incache.erase(it);
				incache.insert(make_pair(i,x));
				continue;
			}
			if(k == incache.size())
				incache.erase(incache.begin());
			incache.insert(make_pair(i,x));
		}
		cout << ans << endl;
	}
}
