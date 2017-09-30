#include<bits/stdc++.h>
using namespace std;

long long pre_sum[10000];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n == 0)
		{
			printf("*\n");
			break;
		}
		memset(pre_sum,0,sizeof(pre_sum));
		for(int i = 0;i<n;i++)
		{
			int s,t,k;
			scanf("%d%d%d",&s,&t,&k);
			pre_sum[s] += k;
			pre_sum[t] -= k;
		}
		for(int i = 1;i<=1000;i++)
			pre_sum[i] += pre_sum[i-1];
		long long ans = 0;
		for(int i = 1;i<=1000;i++)
			ans = max(ans,pre_sum[i]);
		printf("%lld\n",ans);
	}
}
