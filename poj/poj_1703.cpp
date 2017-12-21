#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int N = 2e5 + 7;

int fa[N * 2];

void init()
{
	for(int i = 0;i < N * 2 ; i++)
		fa[i] = i;
}
int find(int x)
{
	if(fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a,int b)
{
	a = find(a), b = find(b);
	if(fa[a] != fa[b])
		fa[a] = fa[b];
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i = 0;i < m; i++)
		{
			char s[5];
			int x,y;
			scanf("%s%d%d",s,&x,&y);
			if(s[0] == 'A')
			{
				if(find(x) == find(y) || find(x + n) == find(y + n))
					puts("In the same gang.");
				else if(find(x) == find(y + n) || find(x + n) == find(y))
					puts("In different gangs.");
				else
					puts("Not sure yet.");
			}
			else
			{
				merge(x,y + n), merge(x + n, y);
			}
		}
	}
}
