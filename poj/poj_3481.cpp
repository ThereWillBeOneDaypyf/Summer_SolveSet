#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

//求区间最大值
//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 2000005;

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
	r = val;
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
	if(!root)
	{
		NewNode(root,k,val,0);
		return;
	}
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
	//NewNode(root,0,-1,0);
	//NewNode(ch[root][1],INF,-1,root);
	//push_up(root);
}
int get_Max()
{
	int r = root;
	while(ch[r][1] && ch[r][1] != 2)
		r = ch[r][1];
	return r;
}
int get_Min()
{
	int r = root;
	while(ch[r][0]&& ch[r][0] != 1)
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
int del(int kind) // 小 0 ，大1
{
	int r = root;
	while(ch[r][kind])
		r = ch[r][kind];	
	splay(r,0);
	if(!root)
		return 0;
	if(!ch[root][0] && !ch[root][1])
	{
		root = 0;
		return r;
	}	
	int pre;
	if(kind==1)
		pre = get_pre();
	else
		pre = get_next();
	ch[pre][kind] = ch[r][kind];
	fa[ch[r][kind]] = pre;
	fa[pre] = 0;
	push_up(pre);
//	if(r == root)
//		root = ch[r][1];
//	else
//		splay(fa[r],0);
	return r;
}
void debug(int r)
{
	if(!r)
		return;
	cout << "fa: " << fa[r] << " key " << key[r] << " r " << r << endl;
	debug(ch[r][0]);
	debug(ch[r][1]);
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
			printf("%d\n",del(1));
		else if(x==3)
			printf("%d\n",del(0));
		else
		{
			int k,p;
			scanf("%d%d",&k,&p);
			insert(p,k);
		}
	//	debug(root);
	}
	return 0;
}
