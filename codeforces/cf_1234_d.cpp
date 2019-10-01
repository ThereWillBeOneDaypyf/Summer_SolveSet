#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
string str;

struct Tree
{
	int l, r;
	int val;
};

Tree t[N * 4];

void debug(int step)
{
	if(t[step].l == t[step].r)
	{
		return;
	}
	debug(step * 2);
	debug(step * 2 + 1);
}

void push_up(int step)
{
	t[step].val = t[step * 2].val | t[step * 2 + 1].val;
}

void build(int l, int r, int step)
{
	t[step].l = l;
	t[step].r = r;
	t[step].val = 0;
	if(l == r)
	{
		char x = str[l - 1];
		auto v = x - 'a';
		t[step].val = (1 << v);
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
	push_up(step);
}

void update(int pos, char x, int step)
{
	if(t[step].l == t[step].r)
	{
		auto v = x - 'a';
		t[step].val = (1 << v);
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	if(pos <= mid)
		update(pos, x, step * 2);
	else update(pos, x, step * 2 + 1);
	push_up(step);
}

int query(int l, int r, int step)
{
	if(t[step].l == l && t[step].r == r)
		return t[step].val; 
	int mid = (t[step].l + t[step].r) / 2;
	if(r <= mid)
		return query(l, r, step * 2);
	else if(l > mid)
		return query(l, r, step * 2 + 1);
	else 
	{
		return query(l, mid, step * 2) | query(mid + 1, r, step * 2 + 1);
	}
}

int main()
{
	int q;
	while(cin >> str >> q) 
	{
		build(1, str.size(), 1);
		// debug(1);
		// cout << endl;
		for(int i = 0; i < q;i ++)
		{
			int type;
			cin >> type;
			if(type == 1)
			{
				int pos;
				char x;
				cin >> pos >> x;
				update(pos, x, 1);
			}
			else 
			{
				int l, r;
				cin >> l >> r;
				int res = query(l, r, 1);
				int cnt = 0;
				for(int i = 0;i < 26; i ++)
					if(res & (1 << i))
						cnt ++;
				cout << cnt << endl;
			}
			// debug(1);
			// cout << endl;
		}
	}	
}
