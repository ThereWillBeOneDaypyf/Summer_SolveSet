#include<bits/stdc++.h>
using namespace std;


int main()
{
	int T;
	scanf("%d",&T);
	int n,a,b;
	int ka = 0;
	while(T--)
	{
		scanf("%d%d%d",&n,&a,&b);
		int GCD = __gcd(a,b);
		int tar = n / GCD;
		printf("Case #%d: ",++ka);
		if(n == 2)
		{
			printf("Iaka\n");
			continue;
		}
		else if(n == 3)
		{
			printf("Yuwgna\n");
			continue;
		}
		if(tar % 2)
			printf("Yuwgna\n");
		else
			printf("Iaka\n");
	}
}
