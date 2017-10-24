#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		int ans = 0;
		for(int i = 0;i<n;i++)
		{
			long long cur;
			scanf("%lld",&cur);
			while(cur)
			{
				int tar = cur % 256;
				if(tar == 97)
					ans ++;
				cur /= 256;
			}
		}
		printf("%d\n",ans);
	}

}
