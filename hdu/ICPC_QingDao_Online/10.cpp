#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int l,r;
	int val;
};
const int N = 1e5 + 7;
Node v[N];
void init(int n)
{
	v[0].r = 1;
	v[0].l = -1;
	for(int i = 1;i<=n+1;i++)
		v[i].l = i - 1,v[i].r = i + 1;	
	v[0].val = -1e9;
	v[n+1].val = 1e9;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n ;
		scanf("%d",&n);
		init(n);
		for(int i = 1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			v[i].val = x;
		}	
		int flag = 1;
		while(flag)
		{
			int p = v[0].r;
			flag = 0;
			while(p <= n)
			{
				if(v[p].val > v[v[p].r].val)
				{
					flag = 1;
					int temp = v[p].r;
					v[v[p].l].r = v[p].r;
					v[v[p].r].l = v[p].l;
					p = temp;
				}
				else p = v[p].r;
			}
		}
		int p = v[0].r;
		vector<int>ans;
		while(p != n + 1)
		{
			ans.push_back(v[p].val);
			p = v[p].r;	
		}
		printf("%d\n",ans.size());
		for(int i = 0;i<ans.size();i++)
		{
			if(i)
				printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
}
