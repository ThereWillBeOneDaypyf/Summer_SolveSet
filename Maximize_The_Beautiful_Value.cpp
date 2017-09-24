#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N];
long long pre[N];
long long sum[N];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		memset(pre,0,sizeof(pre));
		memset(sum,0,sizeof(sum));
		for(int i = 1;i<=n;i++)
		{
			scanf("%d",a + i);
			pre[i] = pre[i-1] + 1LL * i * a[i];
			sum[i] = sum[i-1] + a[i];
		}
		long long ans = 0;
		for(int i = 1;i<=n;i++)
		{
			if(i - k > 0)
			{
				long long temp = pre[n] - (pre[i] - pre[i-k-1]);
				temp += a[i] * (i - k);
				temp += pre[i-1] - pre[i-k-1];
				temp += sum[i-1] - sum[i-k-1];
				ans = max(temp,ans);
			}
		}
		printf("%lld\n",ans);
	}
}
