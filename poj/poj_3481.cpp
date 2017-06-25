#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

//求区间最大值
//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 200005;

int ch[N][2];
int fa[N];
int sz[N];
int v[N];
int tot = 0;
int key[N];
int root;
void push_up(int r)
{
	sz[r] = sz[ch[r][0]] + sz[ch[r][1]] + 1;
}
void NewNode(int &r,int k, int val, int Fa) // 生成一个以Fa为父节点的儿子节点
	// k为关键字，val为值
{
	r = ++ tot;
	ch[r][0] = ch[r][1] = 0;
	key[r] = k;
	v[r] = val;
	sz[r] = 1;
	fa[r] = Fa;
}
void Rotate(int r, int kind) // left 0 right 1
{
	int y = fa[r];
	ch[y][!kind] = ch[r][kind];
	fa[ch[r][kind]] = y;
	if (fa[y])
		ch[fa[y]][ch[fa[y]][1] == y] = r;
	fa[r] = fa[y];
	ch[r][kind] = y;
	fa[y] = r;
	push_up(y);
	push_up(r);
}
void splay(int r, int goal)
{
	while (fa[r] != goal)
	{
		if (fa[fa[r]] == goal)
			Rotate(r, !(ch[fa[r]][1] == r));
		else
		{
			int y =  fa[r];
			int x = fa[fa[r]];
			int kind_xy = ch[x][1] == y;
			int kind_yr = ch[y][1] == r;
			if (kind_xy == kind_yr)
			{
				Rotate(y, !kind_xy);
				Rotate(r, !kind_xy);
			}
			else
			{
				Rotate(r, !kind_yr);
				Rotate(r, !kind_xy);
			}
		}
	}
	if (goal == 0)
		root = r;
	push_up(r);
}
void insert(int k,int val) //将关键字为k值为val的节点插入splay tree
{
	int r = root;
	while(ch[r][ k > key[r]])
		r = ch[r][k > key[r]];
	NewNode(ch[r][k>key[r]],k,val,r);
	splay(ch[r][k>key[r]],0);
}
int key_to_Index(int k) // 将splay 的关键字换成下标
{
	int r = root;
	while(key[r] != k)
	{
		r = ch[r][ k > key[r]];
	}
	return r;
}
void init()
{
	memset(ch,0,sizeof(ch));
	memset(key,0,sizeof(key));
	memset(fa,0,sizeof(fa));
	memset(v,0,sizeof(v));
	memset(sz,0,sizeof(sz));
	tot = 0;
	root = 0;
	//区间查询生成两个防越界的节点,生成的节点v值不影响结果
//	NewNode(root,0,-1,0);
//	NewNode(ch[root][1],n+1,-1,root);
}
int get_Max()
{
	int r = root;
	while(ch[r][1])
		r = ch[r][1];
	return r;
}
int get_Min()
{
	int r = root;
	while(ch[r][0])
		r = ch[r][0];
	return r;
}
int get_pre()
{
	int r = ch[root][0];
	while(ch[r][1])
		r = ch[r][1];
	splay(r,0);
	return r;
}
int get_next()
{
	int r = ch[root][1];
	while(ch[r][0])
		r = ch[r][0];
	splay(r,0);
	return r;
}
void del(int r)
{
	splay(r,0);
	int temp = ch[root][1];
	while(ch[temp][0])
		temp = ch[temp][0];
	splay(temp,root);
	ch[temp][0] = ch[root][0];
	fa[ch[root][0]] = temp;
	fa[temp] = 0;
	root = temp;
}
int main()
{
	int x;
	init();
	while(scanf("%d",&x)==1)
	{
		if(!x)
			break;
		if(x==2)
		{
			if(root==0)
				printf("0\n");
			else
			{
				int y = get_Max();
				printf("%d\n",v[y]);
				del(y);
			}
		}	
		else if(x==3)
		{
			if(root == 0)
				printf("0\n");
			else
			{
				int y = get_Min();
				printf("%d\n",v[y]);
				del(y);
			}
		}
		else
		{
			int k,p;
			scanf("%d%d",&k,&p);
			insert(p,k);
		}
	}
}
