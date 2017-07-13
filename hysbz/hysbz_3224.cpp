#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 2e9+7 

const int N = 500015;

int ch[N][2],fa[N],key[N],sz[N];
int cnt[N];
int n,q;
int tot = 0,root = 0;

int rev[N];
void clean(int r)
{
	ch[r][0] = ch[r][1] = fa[r] = key[r] = sz[r] = cnt[r] = 0;
}
void mid_order(int r)
{
	if(!r)
		return;
	mid_order(ch[r][0]);
	cout << key[r] << " ";
	mid_order(ch[r][1]);
}

void push_up(int r)
{
	if(!r)
		return;
	sz[r] =  cnt[r];
	if(ch[r][0])
		sz[r] += sz[ch[r][0]];
	if(ch[r][1])
		sz[r] += sz[ch[r][1]];
}
void push_down(int r)
{
}
void rotate(int x, int d)
{
	const int y = fa[x];
	ch[y][!d] = ch[x][d];
	if (ch[x][d]) fa[ch[x][d]] = y;
	fa[x] = fa[y];
	if (ch[fa[y]][0] == y) ch[fa[x]][0] = x;
	else if (ch[fa[y]][1] == y) ch[fa[x]][1] = x;
	fa[y] = x;
	ch[x][d] = y;
	push_up(y);
}
bool _splay_parent(int x, int & y, int goal)
{
	return (y = fa[x]) != goal && (ch[y][0] == x || ch[y][1] == x);
}
void splay(int x, int goal)
{
	push_down(x);
	for (int y, z; _splay_parent(x, y, goal);)
	{
		if (_splay_parent(y, z, goal))
		{
			push_down(z);
			push_down(y);
			push_down(x);
			int d = y == ch[z][0];
			if (x == ch[y][d])
				rotate(x, d ^ 1), rotate(x, d);
			else
				rotate(y, d), rotate(x, d);
		}
		else
		{
			push_down(y), push_down(x);
			rotate(x, x == ch[y][0]);
			break;
		}
	}
	push_up(x);
	if (goal == 0) root = x;
}
void NewNode(int &r,int k,int Fa)
{
	r = ++ tot;
	ch[r][0] = ch[r][1] = 0;
	sz[r] = 1;
	key[r] = k;
	cnt[r] = 1;
	fa[r] = Fa,rev[r] = 0;
}
void insert(int r,int val)
{
	if(!root)
	{
		NewNode(root,val,0);
		return;
	}
	if(key[r] == val)
	{
		cnt[r] ++;
		splay(r,0);
		return;
	}
	if(!ch[r][val > key[r]])
	{
		NewNode(ch[r][val>key[r]],val,r);
		splay(ch[r][val > key[r]],0);
		return;
	}
	else insert(ch[r][val>key[r]],val);
}
void init()
{
	tot = root = 0;
	memset(sz,0,sizeof(sz));
	memset(fa,0,sizeof(fa));
	memset(ch,0,sizeof(ch));
	memset(key,0,sizeof(key));
}
int get_kth(int r,int k)
{
	push_down(r);
	int tempszMax = sz[ch[r][0]] + cnt[r];
	int tempszMin = sz[ch[r][0]] + 1;
	if(k >= tempszMin && k <= tempszMax)
		return r;
	else if( k < tempszMin)
		return get_kth(ch[r][0],k);
	else
		return get_kth(ch[r][1],k-tempszMax);
}
int FIND(int r,int k)
{
	if(!r)
		return -1;
	if(key[r] == k)
	{
		splay(r,0);
		return r;
	}
	FIND(ch[r][k > key[r]],k);
}
int get_Min(int r)
{
	push_down(r);
	while(ch[r][0])
	{
		r = ch[r][0];
		push_down(r);
	}
	return r;
}
int get_Max(int r)
{
	push_down(r);
	while(ch[r][1])
	{
		r = ch[r][1];
		push_down(r);
	}
	return r;
}
//ch[ch[root][1]][0]
void cut(int val)
{
	int r = FIND(root,val);
	if(r== -1)
		return;
	splay(r,0);
	if(cnt[r] > 1)
	{
		cnt[r]--;
		return;
	}
	if(ch[r][0] && ch[r][1])
	{
		int old = root;
		int lc = ch[r][0],rc = ch[r][1];
		int tar = lc;
		while(ch[tar][1])
			tar = ch[tar][1];
		ch[tar][1] = rc;
		fa[rc] = tar;
		push_up(tar);
		root = lc;
		fa[lc] = 0;
		splay(tar,0);
		clean(old);
	}
	else if(ch[r][0] || ch[r][1])
	{
		int old = root;
		root = max(ch[r][0],ch[r][1]);
		fa[root] = 0;
		clean(old);
	}
	else
	{
		clean(root);
		root = 0;
	}
}
int get_kless(int r,int k)
{
	int sum = 0;
	if(!r)
		return 0;
	if(key[r] > k)
		return get_kless(ch[r][0],k);
	else if(key[r] < k)	
	{
		sum += cnt[r];
		if(ch[r][0])
			sum += get_kless(ch[r][0],k);
		if(ch[r][1])
			sum += get_kless(ch[r][1],k);
		return sum;
	}
	else if(key[r] == k)
	{
		splay(r,0);
		return 1;
	}
}
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		init();
		for(int i = 0;i<n;i++)
		{
			int op,x;
			scanf("%d%d",&op,&x);
			if(op == 1)
				insert(root,x);
			else if(op == 2)
				cut(x);
			else if(op == 3)
				printf("%d\n",get_kless(root,x));
			else if(op == 4)
				printf("%d\n",key[get_kth(root,x)]);
			else if(op == 5)
			{
				insert(root,x);
				int Index = FIND(root,x);
				if(Index == -1)
					continue;
				splay(Index,0);
				printf("%d\n",key[get_Max(ch[root][0])]);
				cut(x);
			}
			else 
			{
				insert(root,x);
				int Index = FIND(root,x);
				if(Index == -1)
					continue;
				splay(Index,0);
				printf("%d\n",key[get_Min(ch[root][1])]);
				cut(x);
			}
			//cout << " * ";
			//mid_order(root);
			//cout << endl;
		}
	}
	return 0;
}
