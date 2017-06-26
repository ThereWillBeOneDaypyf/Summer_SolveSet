#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


#define INF 0x3f3f3f3f

const int N = 200005;

int ch[N][2];
int fa[N];
int tot = 0;
int key[N];
int v[N];
int sum[N];
int sz[N];
int tar[N];
int rev[N];
int root;
void push_up(int r)
{
	sum[r] = sum[ch[r][0]] + sum[ch[r][1]] + v[r] ;
	sz[r] = sz[ch[r][0]] + sz[ch[r][1]] + 1;
}
void push_down(int r)
{
	if (!tar[r])
		return;
	swap(ch[r][0], ch[r][1]); //区间翻转交换信息 根据具体改变？
	if (ch[r][0])
	{
		tar[ch[r][0]] = tar[r];
		sum[ch[r][0]] = tar[r] * sz[ch[r][0]];
		v[ch[r][0]] = tar[r];
		rev[ch[r][0]] ^= 1;
	}
	if (ch[r][1])
	{
		tar[ch[r][1]] = tar[r];
		sum[ch[r][1]] = tar[r] * sz[ch[r][1]];
		v[ch[r][1]] = tar[r];
		rev[ch[r][1]] ^= 1;
	}
	tar[r] = 0;
	rev[r] = 0;
}
void NewNode(int &r, int k, int val, int Fa) // 生成一个以Fa为父节点的儿子节点
// k为关键字，val为值
{
	r = ++ tot;
	ch[r][0] = ch[r][1] = 0;
	key[r] = k;
	sum[r] = v[r] = val;
	fa[r] = Fa;
	tar[r] = rev[r] = 0;
}
void Rotate(int r, int kind) // left 0 right 1
{
	int y = fa[r];
	push_down(r);
	push_down(y);
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
void insert(int k, int val) //将关键字为k值为val的节点插入splay tree
{
	int r = root;
	while (ch[r][ k > key[r]])
		r = ch[r][k > key[r]];
	NewNode(ch[r][k > key[r]], k, val, r);
	splay(ch[r][k > key[r]], 0);
}
int key_to_Index(int k) // 将splay 的关键字换成下标
{
	int r = root;
	while (key[r] != k)
	{
		r = ch[r][ k > key[r]];
	}
	return r;
}
int get_pre(int r) // 求前驱
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
int get_next(int r) // 求后继
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
void update(int k, int val) // 单点更新关键字为k,v为 val
{
	int pos = key_to_Index(k);
	v[pos] = val;
	splay(pos, 0);
}
void update_interval(int l, int r, int val)
{
	l = key_to_Index(l - 1);
	r = key_to_Index(r + 1);
	splay(l, 0);
	splay(r, l);
	sum[ch[r][0]] =  sz[ch[r][0]] * val;
	v[ch[r][0]] = val;
	tar[ch[r][0]] = val;
}
int query(int l, int r) // 区间查询l，r 之间的最大值
{
	l = key_to_Index(l - 1);
	r = key_to_Index(r + 1);
	splay(l, 0);
	splay(r, l);
	return sum[ch[r][0]];
}
void flip(int l, int r)
{
	l = key_to_Index(l - 1);
	r = key_to_Index(r + 1);
	splay(l, 0);
	splay(r, l);
	rev[ch[r][0]] ^= 1;
}
void init(int n)
{
	memset(ch, 0, sizeof(ch));
	memset(key, 0, sizeof(key));
	memset(fa, 0, sizeof(fa));
	memset(v, 0, sizeof(v));
	memset(sum, 0, sizeof(sum));
	memset(sz, 0, sizeof(sz));
	tot = 0;
	root = 0;
	//区间查询生成两个防越界的节点,生成的节点v值不影响结果
	NewNode(root, 0, 0, 0);
	NewNode(ch[root][1], n + 1, 0, root);
}
void debug(int r)
{
	if (!r)
		return;
	debug(ch[r][0]);
	cout << key[r] << " " << sum[r] << endl;
	debug(ch[r][1]);
}
int main()
{
	int T;
	scanf("%d", &T);
	int ka = 0;
	while (T--)
	{
		int n;
		scanf("%d", &n);
		init(n);
		for (int i = 1; i <= n; i++)
			insert(i, 1);
		int q;
		scanf("%d", &q);
		for (int i = 0 ; i < q; i++)
		{
			int l, r, val;
			scanf("%d%d%d", &l, &r, &val);
			update_interval(l, r, val);
//			cout << root << endl;
//			debug(root);
		}
		printf("Case %d: The total value of the hook is %d.\n", ++ka, query(1, n));
	}
	return 0;
}