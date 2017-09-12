#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 8;

int v[N];
vector<int>a;
int c1[N],c2[N];
int main()
{
	int T;
	cin >> T;
	int ka = 0;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		a.clear();
		for(int i = 0;i<n;i++)
		{
			cin >> v[i];
			a.push_back(v[i]);
		}
		sort(v,v+n);
		for(int i = 0;i<n-1;i++)
			a.push_back(v[i]*2),a.push_back(v[i]*3);	
		a.push_back(v[n-1] * 2);
		sort(a.begin(),a.end());
		int cnt = unique(a.begin(),a.end()) - a.begin();
		memset(c1,0,sizeof(c1)),memset(c2,0,sizeof(c2));
		c1[0] = 1,c2[0] = 1;
		for(int i = 1;i<=k;i++)
		{
			for(int j = 1;j<=*a.rbegin() * i;j ++)
			{
				for(auto x : a)
				{
					if(c1[j])
					{
						c2[j+x] = 1;
					}
				}
			}
			for(int j = 1;j<=*a.rbegin() * i;j++)
				c1[j] = c2[j],c2[j] = 0;
		}
		int ans = 0;
		for(int i = 0;i<N;i++)
			if(c1[i])
				ans ++;
		cout << "Scenario #" << ++ ka << ":" << endl;
		cout << ans << endl;
		cout << endl;
	}
}
