#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

long long x[4];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		if(N == 1)
		{
			printf("4\n");
			continue;
		}
		long long n;
		for(n = 1;n<=N;n++)
		{
			if(2 * n * n <= N && N <= 2 * (n + 1) * (n + 1))
			   break;
		}
		if(N == 2 * n * n)
			printf("%lld\n",4 *n);
		else if(2 * n * n < N && N < 2 * n * n + n)
			printf("%lld\n",4 * n + 1);
		else if(2 * n * n + n <= N && N <= 2 * n * n + 2 * n)
			printf("%lld\n",4 * n + 2);
		else if(2 * n * n + 2 * n < N && N <= 2 * n * n + 3 * n)
			printf("%lld\n",4 * n + 3);
		else 
			printf("%lld\n",4 * n + 4);
	}
}
