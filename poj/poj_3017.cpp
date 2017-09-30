#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;

const int N = 1e5 + 7;

pair<int,int> que[2 * N];
int a[N];
long long dp[N];

int main()
{
	int n;
	long long m;
	while(scanf("%d%lld",&n,&m) == 2)
	{
		int head = 1,rear = 0;
		long long sum = 0;
		int pos = 1;
		int flag = 1;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",a + i);
			if(a[i] > m)
				flag = 0;
		}
		if(!flag)
			printf("-1\n");
		else
		{
			sum = a[1];
			pos = 1;
			dp[1] = a[1];	
			que[++rear] = make_pair(a[1],1);
			for(int i = 2;i<=n;i++)
			{
				sum += a[i];
				while(sum > m && pos < i)
					sum -= a[pos++];
				while(head <= rear && que[rear].first <= a[i])
					rear --;	
				que[++rear] = make_pair(a[i],i);		
				while(head <= rear && que[head].second < pos)
					head++;
				// dp[i] = dp[que[rear - 1].second] + a[i];
				dp[i] = dp[pos - 1] + que[head].first;
				for(int j = head;j <= rear - 1;j++)
					dp[i] = min(dp[que[j].second] + que[j+1].first,dp[i]);
			}
			printf("%lld\n",dp[n]);
		}
	}
	return 0;
}
