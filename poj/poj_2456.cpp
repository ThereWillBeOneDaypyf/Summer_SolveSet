#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 100005;
const long long Max_l = 1e9+5;
int pos[N];
int m,n;
bool judge(long long tar)
{
	long long cur = pos[0];
	int j = 1;
	for(int i =1 ;i < m;i++)
	{
		while( j < n && pos[j] < cur + tar)
			j ++;
		if(j == n)
			return false;
		cur = pos[j];
	}	
	return true;
}

int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i =0 ;i<n;i++)
			scanf("%d",pos+i);
		sort(pos,pos+n);
		long long l = 0,r = Max_l;
		long long mid;
		long long ans = 0;
		while(l <= r)
		{
			mid = (l + r) /2;
			if(judge(mid))
			{
				ans = mid ;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		printf("%lld\n",ans);
	}
}
