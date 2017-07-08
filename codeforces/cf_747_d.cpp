#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e5+5;

int n,k;
int a[N];
int pos[N];
int ans[N];

int main()
{
	while(scanf("%d%d",&n,&k) == 2)
	{
		int cnt = 0;
		for(int i = 0;i<n;i++)
		{
			scanf("%d",a+i);
			if(a[i] < 0)
				pos[cnt++] = i;
		}
		if(cnt > k)
			printf("-1\n");
		else if(!cnt)
			printf("0\n");
		else
		{
			int ret = k - cnt;
			int res = 2 * cnt;
			map<int,int>m;
			m.clear();
			for(int i = 1;i<cnt;i++)
				m[pos[i] - pos[i-1] - 1]++;
			map<int,int> :: iterator it;
			for(it = m.begin();it != m.end();it++)
			{
				int len = it-> first;
				int amount = it -> second;
				if(len > ret)
					break;
				if(len*amount <= ret)
				{
					res -= amount * 2;
					ret -= len * amount;
				}
				else if(len * amount > ret)
				{
					int can = ret / len;
					ret -= can * len;
					res -= can * 2;
				}
			}
			if(ret >= (n - pos[cnt-1] - 1))
				res -= 1;
			printf("%d\n",res);
		}
	}
	return 0;
}
