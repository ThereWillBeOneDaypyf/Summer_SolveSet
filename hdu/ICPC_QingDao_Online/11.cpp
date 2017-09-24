#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		scanf("%lld",&n);
		int flag = 0;
		for(long long i = 1;i<=1e6 + 1;i++)
		{
			long long a = i + 1;
			long long temp = - i * i * i + a * a * a ; 
			if(temp == n)
			{
				flag = 1;
				printf("YES\n");
				break;
			}
		}
		if(!flag)
			printf("NO\n");
	}
}
