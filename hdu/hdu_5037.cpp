#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
vector<int>v;
int main()
{
	int T;
	scanf("%d",&T);
	int ka = 0;
	while(T--)
	{
		v.clear();
		int n,m,l;
		scanf("%d%d%d",&n,&m,&l);
		for(int i = 0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			v.push_back(x);
		}
		v.push_back(m);
		sort(v.begin(),v.end());
		int ans = 0;
		int cur = 0;
		int pre = -l;
		for(int i = 0;i != v.size();i++)
		{
			ans += (v[i] - cur) / (l + 1) * 2;
			pre += (v[i] - cur) / (l + 1) * (l + 1);
			if(pre + l < v[i])
			{
				pre = cur + (v[i] - cur) / (l + 1) * (l + 1);
				cur = v[i];	
				ans ++;
			}
			else cur = v[i];
		}
		printf("Case #%d: %d\n",++ka ,ans);
	}
	return 0;
}

