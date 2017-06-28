#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 8;

struct wood
{
	int l,w;
	int vis;
	bool operator < (const wood &rhs) const
	{
		return l < rhs.l || (l == rhs.l && w < rhs.w);
	}
}a[N];

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		memset(a,0,sizeof(a));
		cin >> n;
		for(int i = 0;i<n;i++)
			cin >> a[i].l >> a[i].w;
		sort(a,a+n);
		int ans = 0;
		for(int i = 0;i<n;i++)
		{
			if(!a[i].vis)
			{
				ans ++;
				int temp_l = a[i].l;
				int temp_w = a[i].w;
				a[i].vis = 1;
				for(int j = i+1;j < n;j++)
				{
					if(!a[j].vis && temp_l <= a[j].l && temp_w <= a[j].w)
					{
						temp_l = a[j].l;
						temp_w = a[j].w;
						a[j].vis = 1;
					}
				}
			}
		}
		cout << ans << endl;
	}
}
