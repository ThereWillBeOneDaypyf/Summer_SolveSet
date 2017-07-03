#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 2e5 + 7;

vector<pair<int,int> > l[N];
vector<pair<int,int> > r[N];
long long c[N];

int main()
{
	int n,x;
	while(cin >> n >> x)
	{
		for(int i = 0;i<n;i++)
		{
			int ll,rr,cc;
			cin >> ll >> rr >> cc;
			l[ll].push_back(make_pair(rr - ll + 1 ,cc));
			r[rr].push_back(make_pair(rr - ll + 1 ,cc));	
		}
		for(int i = 0;i< N;i++)
			c[i] = INF;
		long long ans = 2 * INF;
		for(int i = 1;i<=200000;i++)
		{
			for(int j = 0;j<l[i].size();j++)
			{
				int len = l[i][j].first;
				int cost = l[i][j].second;
				if(len >= x)
					continue;
				if(c[x - len] != INF)
					ans = min(ans,c[x-len] + cost);
			}
			for(int j = 0;j<r[i].size();j++)
			{
				long long len = r[i][j].first;
				long long cost = r[i][j].second;
				c[len] = min(c[len] ,cost);
			}
		}
		if(ans == 2*INF)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}	
	return 0;
}
