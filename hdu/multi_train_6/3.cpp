#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 8;

struct Node
{
	int id;
	int val;
	bool operator < (Node & rhs) const
	{
		return val > rhs.val;
	}
}a[N];
int b[N];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i =1;i<=n;i++)
		{
			scanf("%d",&a[i].val);	
			a[i].id = i;
		}
		sort(a+1,a+1+n);	
		for(int i =2;i<=n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(a[j].id % i !=0)
				{
				   b[i] = a[j].val;	
				   break;
				}
			}
		}
		for(int i = 2;i<=n;i++)
		{
			if(i != 2)
				printf(" ");
			printf("%d",b[i]);
		}
		printf("\n");
	}
}
