#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N = 300015;

int ch[N][2], fa[N], key[N], sz[N];
int sum[N];
int v[N];
int n, q;
int tot = 0, root = 0;

int rev[N];

void mid_order(int r);

void push_up(int r)
{
	if (!r)
		return;
	sz[r] = sz[ch[r][0]] + sz[ch[r][1]] + 1;
	sum[r] = sum[ch[r][0]] + sum[ch[r][1]] + key[r];
}
void push_down(int r)
{
	if (rev[r])
	{
		swap(ch[r][0], ch[r][1]);
		if (ch[r][0])
			rev[ch[r][0]] ^= 1;
		if (ch[r][1])
			rev[ch[r][1]] ^= 1;
		rev[r] = 0;
	}
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
void NewNode(int &r, int k, int Fa)
{
	r = ++ tot;
	ch[r][0] = ch[r][1] = 0;
	sz[r] = 1;
	key[r] = k;
	fa[r] = Fa, rev[r] = 0;
}
void build(int &r, int L, int R, int Fa)
{
	if (L > R)
		return;
	int mid = (L + R) / 2;
	NewNode(r, v[mid], Fa);
	build(ch[r][0], L, mid - 1, r);
	build(ch[r][1], mid + 1, R, r);
	push_up(r);
}
void init()
{
	tot = root = 0;
	memset(sz, 0, sizeof(sz));
	memset(fa, 0, sizeof(fa));
	memset(ch, 0, sizeof(ch));
	memset(key, 0, sizeof(key));
	NewNode(root, 0, 0);
	NewNode(ch[root][1], 0, root);
	build(ch[ch[root][1]][0], 1, n, ch[root][1]);
	push_up(ch[root][1]);
	push_up(root);
}
int get_kth(int r, int k)
{
	push_down(r);
	int tempsz = sz[ch[r][0]] + 1;
	if (tempsz == k)
		return r;
	else if (k < tempsz)
		return get_kth(ch[r][0], k);
	else
		return get_kth(ch[r][1], k - tempsz);
}
int get_Min(int r)
{
	push_down(r);
	while (ch[r][0])
	{
		r = ch[r][0];
		push_down(r);
	}
	return r;
}
void flip(int l, int r)
{
	if (l == r)
		return;
	l = get_kth(root, l);
	r = get_kth(root, r + 2);
	splay(l, 0);
	splay(r, root);
	rev[ch[ch[root][1]][0]] ^= 1;
}
//ch[ch[root][1]][0]
void cut(int l, int r, int pos)
{
	//duan kai
	l = get_kth(root, l);
	r = get_kth(root, r + 2);
	pos = get_kth(root, pos + 1);
	splay(l, 0);
	splay(r, root);
	int temp_r = ch[ch[root][1]][0];
	ch[ch[root][1]][0] = 0;
	push_up(ch[root][1]);
	push_up(root);
	splay(pos, 0);
	int need = get_Min(ch[root][1]);
	splay(need, root);
	ch[ch[root][1]][0] = temp_r;
	fa[ch[ch[root][1]][0]] = ch[root][1];
	push_up(ch[root][1]);
	push_up(root);
	splay(temp_r, 0);
}
int cnt = 0;
void mid_order(int r)
{
	if (!r)
		return;
	push_down(r);
	mid_order(ch[r][0]);
	if (cnt >= 1 && cnt <= n)
	{
		if (cnt > 1)
			printf(" ");
		printf("%d", key[r]);
	}
	cnt ++;
	mid_order(ch[r][1]);
}
int query(int l, int r)
{
	l = get_kth(root, l);
	r = get_kth(root, r + 2);
	splay(l, 0);
	splay(r, l);
	return sum[ch[r][0]];
}
int main()
{
	while (scanf("%d%d", &n, &q) != EOF)
	{
		for (int i =  1; i <= n; i++)
			scanf("%d", v + i);
		init();
		for (int i = 0 ; i < q; i++)
		{
			int op;
			int x, y;
			scanf("%d%d%d", &op, &x, &y);
			if (op == 2)
			{
				int z;
				scanf("%d", &z);
				cut(x, y, z);
			}
			else
				printf("%d\n", query(x, y));
		}
	}
	return 0;
}