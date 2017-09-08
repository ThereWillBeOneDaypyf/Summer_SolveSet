#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
const int N = 1e6 + 7;
map<long long,int> cnt;
long long a[N];
int main()
{
	int T;
	scanf("%d",&T);
	int ka = 0;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		cnt.clear();
		for(int i = 1;i<=n;i++)
			scanf("%lld",a + i);
		for(int i = 1;i<=n;i++)
		{
			long long s = 10000 - (100 -a[i]) * (100 - a[i]);
			cnt[s] ++;
		}
		set<int>s;
		printf("Case #%d:\n",++ka);
		for(auto x : cnt)
			s.insert(x.second);
		if(s.size() == 1 && cnt.size() != 1)
			printf("Bad Mushroom\n");
		else
		{
			int tar = *s.rbegin();
			int t = 0;
			for(auto x : cnt)
			{
				if(x.second == tar)
				{
					if(t)
						printf(" ");
					printf("%lld",x.first);
					t ++;
				}
			}	
			printf("\n");
		}
	}		
}
