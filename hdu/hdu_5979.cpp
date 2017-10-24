#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,d;
	while(scanf("%d%d",&n,&d) == 2)
	{
		int ang;
		double ans = 0;
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&ang);
			ans += 1.0 * d * d * sin(1.0 * ang * acos(-1.0) / 180.0);
		}
		printf("%.3lf\n",ans / 2);
	}
}
