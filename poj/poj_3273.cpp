#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5+5;
const long long Max_R = 1e9 + 5;
int n,m;
long long a[N];

bool judge(long long tar)
{
	int cnt = 0 ;
	long long sum = 0;
	for(int i = 0;i < n;i++)
	{
		if(a[i] > tar)
			return false;
		if(sum + a[i] > tar)
		{
			cnt ++ ;
			sum = a[i];
		}
		else
			sum += a[i];
	}
	return cnt < m;
}

int main()
{
	while(cin >> n >> m)
	{
		for(int i =0 ;i<n;i++)
			scanf("%lld",a + i);
		long long l  = 0,r = Max_R;
		long long mid;
		long long ans = 0;
		while(l <= r)
		{
			mid = (l+r)/2;
			if(judge(mid))
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}	
		printf("%lld\n",ans);
	}
}
