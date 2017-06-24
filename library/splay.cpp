#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 1e5 + 7;

int ch[N][2], sz[N];
int fa[N];
int tot = 0;
int key[N];
int root;
void init()
{
	memset(ch, 0, sizeof(ch));
	memset(sz, 0, sizeof(sz));
	memset(fa, 0, sizeof(-1));
	memset(key, 0, sizeof(key));
	tot = 0;
	root = tot;
}
void push_up(int r)
{
	sz[r] = sz[ch[r][0]] + sz[ch[r][1]];
}
void NewNode(int &r, int val, int Fa)
{
	r = ++tot;
	ch[r][0] = ch[r][1] = 0;
	key[r] = val;
	fa[r] = Fa;
	sz[r] = 1;
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
int insert(int r, int val)
{
	//cout << key[r] << " ";
	if (val == key[r])
	{
		splay(r, 0);
		return 1;
	}
	if (ch[r][key[r] < val] == 0)
	{
		NewNode(ch[r][key[r] < val], val, r);
		splay(ch[r][key[r] < val], 0);
		return 0;
	}
	else return insert(ch[r][key[r] < val], val);
	push_up(r);
}
int get_pre(int r)
{
	if (ch[r][0])
	{
		r = ch[r][0];
		while (ch[r][1])
			r = ch[r][1];
		return key[r];
	}
	else
		return INF;
}
int get_next(int r)
{
	if (ch[r][1])
	{
		r = ch[r][1];
		while (ch[r][0])
			r = ch[r][0];
		return key[r];
	}
	else
		return INF;
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		init();
		int ans = 0;
		for (int i = 0 ; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if (insert(root, x))
				continue;
			else
			{
				if (i == 0)
				{
					ans += x;
					continue;
				}
				int ans1 = abs(x - get_next(root));
				int ans2 = abs(x - get_pre(root));
				// cout << ans1 << " " << ans2 << endl;
				ans += (min(ans1, ans2));
			}
		}
		printf("%d\n", ans);
	}
}