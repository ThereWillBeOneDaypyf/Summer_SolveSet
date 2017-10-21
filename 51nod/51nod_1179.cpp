#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int vis[N];

int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		memset(vis,0,sizeof(vis));
		int Max = 0;
		for(int i = 1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			Max = max(Max,x);
			for(int j = 1;j<=sqrt(x);j++)
			{
				if(x % j == 0)
				{
					if(j * j == x)
						vis[j] ++;
					else
						vis[j] ++, vis[x / j] ++;
				}
			}
		}
		int ans = 1;
		for(int i = Max;i>=1;i--)
			if(vis[i] >= 2)
			{
				ans = i;
				break;
			}
		printf("%d\n",ans);
	}

}
