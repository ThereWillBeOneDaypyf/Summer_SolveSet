#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

struct Tree
{
	int lt,rt;
	int sum;
}t[N * 40];

int root[N];
int tot = 0;

void init_node(Tree& x)
{
	x.lt = x.rt = x.sum = 0;
}

void init()
{
	tot = 0;
	init_node(t[tot]);
	memset(root,0,sizeof(root));
}

int new_node()
{
	tot ++;
	init_node(t[tot]);
	return tot;
}

void cp(Tree &y,Tree x)
{
	y.lt = x.lt, y.rt = x.rt;
	y.sum = x.sum;
}

void push_up(int step)
{
	t[step].sum = t[t[step].lt].sum + t[t[step].rt].sum;
}

void update(int l,int r,int pos,int x,int& y)
{
	y = new_node();
	cp(t[y],t[x]);
	if(l == r)
	{
		t[y].sum ++;
		return;
	}
	int mid = (l + r) / 2;
	if(pos <= mid)
		update(l,mid,pos,t[x].lt,t[y].lt);
	else update(mid + 1, r, pos,t[x].rt,t[y].rt);
	push_up(y);
}

int query(int l,int r,int ql,int qr,int x,int y)
{
	if(l == ql && r == qr)
		return t[y].sum - t[x].sum;
	int mid = (l + r) / 2;
	if(qr <= mid)
		return query(l,mid,ql,qr,t[x].lt,t[y].rt);
	else if(ql > mid)
		return query(mid+1,r,ql,qr,t[x].rt,t[y].rt);
	else return query(l,mid,ql,mid,t[x].lt,t[y].lt) + query(mid + 1,r,mid+1,qr,t[x].rt,t[y].rt);
}

int main()
{
	int n;
	while(cin >> n)
	{
		init();
		long long ans = 0;
		vector<int> v;
		for(int i = 1;i <= n;i ++)
		{
			int x;
			cin >> x;
			v.push_back(x);
			x = min(x,n);
			update(1,n,x,root[i - 1],root[i]);
		}
		for(int i = 2;i <= n;i ++)
		{
			ans += query(1,n,i,n,root[0],root[min(i - 1,v[i - 1])]);
		}
		cout << ans << endl;
	}
}