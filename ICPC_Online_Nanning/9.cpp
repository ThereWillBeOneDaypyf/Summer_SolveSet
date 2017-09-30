#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int v[N];
int cnt = 0;
int vis[N];
void insert(int x)
{
	if(x >= 10000)
	{
		x -= 10000;
		v[cnt] = x;
		vis[cnt++] = 1;
	}
	else if(x >= 0)
		v[cnt++] = x;
}
int len[N*5];

int main()
{
	int x;
	char op;
	memset(vis,0,sizeof(vis));
	while(scanf("%d",&x) == 1)
	{
		insert(x);
	}
	int l = 0;
	if(vis[0])
	{
		for(int i = 0;i < 5;i++)
			len[i] = v[0];
		l = 5;
	}
	else len[l++] = v[0];	
	for(int i = 1;i<cnt;i++)
	{
		if(v[i] >= len[l-1])
		{
			if(vis[i])
			{
				for(int j = l;j < l + 5;j++)
					len[j] = v[i];
				l += 5;
			}
			else
				len[l++] = v[i];
		}
		else
		{
			int pos = upper_bound(len,len+l,v[i]) - len;
			if(vis[i])
			{
				for(int j = pos;j < pos + 5;j++)
					len[j] = v[i];
				l = max(l,pos+5);
			}
			else
				len[pos] = v[i];
		}
		for(int j = 0;j<l;j++)
			cout << len[j] << " ";
		cout << endl;
	}
	printf("%d\n",l);
}
