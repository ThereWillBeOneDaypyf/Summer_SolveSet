#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 7;

struct Tree
{
	int l, r;
	int Max, Min;
} t[N * 4];
void push_up(int step)
{
	t[step].Max = max(t[step * 2].Max, t[step * 2 + 1].Max);
	t[step].Min = min(t[step * 2].Min, t[step * 2 + 1].Min);
}
void build(int l, int r, int step)
{
	t[step].l = l , t[step].r = r, t[step].Min = 1e9, t[step].Max = -1e9;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
}
void update(int x, int val, int step)
{
	if (t[step].l == t[step].r)
	{
		t[step].Min = t[step].Max = val;
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	if (x <= mid)
		update(x, val, step * 2);
	else update(x, val, step * 2 + 1);
	push_up(step);
}
pair<int, int> query(int l, int r, int step)
{
	if (t[step].l == l && t[step].r == r)
		return make_pair(t[step].Min, t[step].Max);
	int mid = (t[step].l + t[step].r) / 2;
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else
	{
		pair<int, int> temp = query(l, mid, step * 2);
		pair<int, int> temp1 = query(mid + 1, r, step * 2 + 1);
		return make_pair(min(temp.first, temp1.first), max(temp.second, temp1.second));
	}
}
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf + 1;
inline void rnext()
{
	if (++ps == pe)
		pe = (ps = buf) + fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
}

template <class T>
inline bool in(T &ans)
{
	ans = 0;
	T f = 1;
	if (ps == pe) return false; //EOF
	do
	{
		rnext();
		if ('-' == *ps) f = -1;
	}
	while (!isdigit(*ps) && ps != pe);
	if (ps == pe) return false; //EOF
	do
	{
		ans = (ans << 1) + (ans << 3) + *ps - 48;
		rnext();
	}
	while (isdigit(*ps) && ps != pe);
	ans *= f;
	return true;
}
const int  MAXOUT = 10000;
char bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
inline void write()
{
	fwrite(bufout, sizeof(char), pout - bufout, stdout);
	pout = bufout;
}
inline void out_char(char c) { *(pout++) = c; if (pout == pend) write();}
inline void out_str(char *s)
{
	while (*s)
	{
		*(pout++) = *(s++);
		if (pout == pend) write();
	}
}
template <class T>
inline void out_int(T x)
{
	if (!x)
	{
		out_char('0');
		return;
	}
	if (x < 0) x = -x, out_char('-');
	int len = 0;
	while (x)
	{
		outtmp[len++] = x % 10 + 48;
		x /= 10;
	}
	outtmp[len] = 0;
	for (int i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
	out_str(outtmp);
}
int a[N];
int ans1[N], ans2[N];
int main()
{
	int n, k;
	while (in(n))
	{
		in(k);
		int cnt = 1;
		for (int i = 1; i <= n; i++)
			in(a[i]);
		build(1, k, 1);
		for (int i = 1; i <= k; i++)
			update(i, a[i], 1);
		ans1[0] = t[1].Min, ans2[0] = t[1].Max;
		for (int i = k + 1; i <= n; i++)
		{
			if (i % k == 0)
				update(k, a[i], 1);
			else update(i % k , a[i], 1);
			ans1[i - k] = t[1].Min, ans2[i - k] = t[1].Max;
			cnt ++;
		}
		for (int i = 0; i < cnt; i++)
		{
			if (i)
				out_char(' ');
			out_int(ans1[i]);
		}
		out_char('\n');
		for (int i = 0; i < cnt; i++)
		{
			if (i)
				out_char(' ');
			out_int(ans2[i]);
		}
		out_char('\n');
	}
	write();
}