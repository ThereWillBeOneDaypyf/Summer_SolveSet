#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...



struct Node
{
	int val;
	char type;
}a[10000];
int n,k;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		int sum_l = 0;
		int sum_d = 0;
		int sum_n = 0;
		for(int i = 1;i<=n;i++)
			scanf("%d",&a[i].val);
		getchar();
		char x;
		for(int i = 1;i<=n;i++)
			scanf("%c%c",&a[i].type,&x);
		for(int i = 1;i<=n;i++)
		{
			if(a[i].type == 'N')
				sum_n += a[i].val;	
			else if(a[i].type == 'L')
				sum_l += a[i].val;
			else
				sum_d += a[i].val;
		}
		if(sum_l+sum_n >= k && -sum_d - sum_n <= k)
			printf("yes\n");
		else
			printf("no\n");
	}
}
