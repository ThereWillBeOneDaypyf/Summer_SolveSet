#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N =1e5 + 5;
typedef long long ll;

ll pre_sum[N];

int main()
{
	int n,q;
	while(scanf("%d%d",&n,&q)==2)
	{
		for(int i = 1; i<= n;i ++)
		{
			int x;
			scanf("%d",&x);
			pre_sum[i] = pre_sum[i-1] + x; 
		}
		for(int i  = 0;i<q;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",pre_sum[r] - pre_sum[l-1]);
		}
	}
}
