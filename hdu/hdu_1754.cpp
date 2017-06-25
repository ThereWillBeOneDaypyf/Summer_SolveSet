#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 200005;

int ch[N][2];
int fa[N];
int key[N];
int Max[N];
int v[N];
int tot = 0;
int root = 0;
void NewNode(int &r,int k,int val,int Fa)
{
	r = ++ tot ;
	ch[r][0] = ch[r][1] = 0;
	key[r] = k;
	v[r] = val;
	Max[r] = val;
	fa[r] = Fa;
}
void push_up(int r)
{
	Max[r] = max(max(Max[ch[r][0]] , Max[ch[r][1]]),v[r]);
}
void init()
{
	tot = 0;
	memset(ch,0,sizeof(ch));
	memset(key,0,sizeof(key));
	memset(Max,0,sizeof(Max));
	memset(fa,0,sizeof(fa));
	memset(v,0,sizeof(v));
	int r;
}
void Rotate(int r,int kind) // 0 left 1 right
{
	int y = fa[r];
	fa[ch[r][kind]] = y;
	ch[y][!kind] = ch[r][kind];
	if(fa[y])
		ch[fa[y]][ch[fa[y]][1] == y] = r;
	fa[r] = fa[y];
	ch[r][kind] = y;
	fa[y] = r;
	push_up(y);
	push_up(r);
}
void splay(int r,int goal)
{
	while(fa[r] != goal)
	{
		if(fa[fa[r]] == goal)
			Rotate(r,ch[fa[r]][0] == r);
		else
		{
			int x = fa[fa[r]];
			int y = fa[r];
			int kind_xy = ch[x][0] == y;
			int kind_yr = ch[y][0] == r;
			if(kind_xy == kind_yr)
			{
				Rotate(y,kind_xy);
				Rotate(r,kind_yr);
			}
			else
			{
				Rotate(r,kind_yr);
				Rotate(r,kind_xy);
			}
		}
	}
	if(!goal)
		root = r;
	push_up(r);	
}
void insert(int k,int val)
{
	int r = root;
	while(ch[r][k > key[r]])
		r = ch[r][k > key[r]];
	NewNode(ch[r][k > key[r]],k,val,r);
	splay(ch[r][k > key[r]] , 0);
}
void update(int pos,int val)
{
	v[pos] = val;
	splay(pos,0);
}
int key_to_Index(int tar)
{
	int r = root;
	while(key[r] != tar)
		r = ch[r][tar > key[r]]; 
	return r;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		init();
		NewNode(root,0,-1,0);
		NewNode(ch[root][1],n+1,-1,root);
		for(int i = 1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			insert(i,x);
		}
		for(int i = 0;i<m;i++)
		{
			char op[5];
			int x,y;
			scanf("%s%d%d",op,&x,&y);
			if(op[0]=='Q')
			{
				int l = key_to_Index(x-1);
				int r = key_to_Index(y+1);
				splay(l,0);
				splay(r,l);	
				printf("%d\n",Max[ch[r][0]]);
			}
			else
			{
				int pos = key_to_Index(x);
				update(pos,y);
			}
	//		for(int i = 3;i<=tot;i++)
	//			cout << key[i] << " " << Max[i] << endl;
		}
	}
}

