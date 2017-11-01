#include<bits/stdc++.h>
using namespace std;


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		long long ans = 0;
		for(int i = 0;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			ans += 1LL * a * b;
		}
		printf("%lld\n",ans);
	}
}

