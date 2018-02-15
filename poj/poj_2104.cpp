#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e5 + 7;

struct Tree
{
	int lt,rt; // next lson rson;
	int sum;
}t[N * 40];

int cnt = 0;

void init_node(Tree &cp)
{
	cp.lt = cp.rt = cp.sum = 0;
}

void init()
{
	init_node(t[0]);
	cnt = 0;
}

int new_son()
{
	cnt ++;
	init_node(t[cnt]);
	return cnt;
}
void cpy_node(Tree rhs,Tree &tar)
{
	tar.lt = rhs.lt,tar.rt = rhs.rt;
	tar.sum = rhs.sum;
}

int root[N];

void push_up(int x)
{
	t[x].sum = t[t[x].lt].sum + t[t[x].rt].sum;
}

void update(int l,int r,int pos,int &x,int y)
{
	x = new_son();
	cpy_node(t[y],t[x]);
	if(l == r)
	{
		t[x].sum ++;
		return;
	}
	int mid = (l + r) / 2;
	if(pos <= mid)
		update(l,mid,pos ,t[x].lt,t[y].lt);
	else update(mid + 1,r,pos,t[x].rt,t[y].rt);
	push_up(x);
}

int query(int l,int r,int k,int x,int y)
{
	if(l == r)
		return l;
	int sum = t[t[y].lt].sum - t[t[x].lt].sum;
	int mid = (l + r) /  2;
	if(k <= sum)
		return query(l,mid,k,t[x].lt,t[y].lt);
	else
		return query(mid + 1, r, k - sum, t[x].rt,t[y].rt);
}
int get_id(const vector<int> v,int tar)
{
	return lower_bound(v.begin(),v.end(),tar) - v.begin() + 1;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) == 2)
	{
		vector<int>v;
		init();
		for(int i = 0;i < n;i++)
		{
			int x;
			scanf("%d",&x);
			v.push_back(x);
		}
		vector<int> tar(v);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		for(int i = 0;i < n;i++)
			update(1,v.size(),get_id(v,tar[i]),root[i + 1],root[i]);
		for(int i = 0;i < m;i++)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",v[query(1,v.size(),k,root[l - 1],root[r]) - 1]);
		}
	}
}