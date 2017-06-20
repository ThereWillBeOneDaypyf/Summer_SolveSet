#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6+8;
typedef long long ll;
int l[N],r[N];
int a[N];

int main()
{
	int n;
	while(scanf("%d",&n) == 1 && n) 
	{
		for(int i =0 ;i< n;i++)
			scanf("%d",a+i);
		for(int i =0 ;i<n;i++)
			l[i] = r[i] = i;
		for(int i =1 ;i<n;i++)
		{
			int cur = i;
			while( cur > 0 && a[i] <= a[cur-1])
				cur = l[cur-1];
			l[i] = cur;
		}
		for(int i = n-2 ; i >= 0; i --)
		{
			int cur = i;
			while( cur < n- 1&& a[i] <= a[cur+1])
				cur = r[cur+1];
			r[i] = cur;
		}
		ll ans = 0;
		for(int i = 0;i<n;i++)
		{
			ans = max(ans , (ll) a[i] * (r[i] - l[i] + 1));
		}
		printf("%lld\n",ans);
	}
}
