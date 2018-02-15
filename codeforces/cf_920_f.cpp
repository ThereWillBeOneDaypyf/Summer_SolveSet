#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e6 + 7;

int f[N];

struct Tree
{
    int l, r, step;
    long long sum;
    int fin;
} t[N * 4];

void push_up(int step)
{
    t[step].sum = t[step * 2].sum + t[step * 2 + 1].sum;
    t[step].fin = t[step * 2].fin & t[step * 2 + 1].fin;
}
int solve(int x)
{
    if (f[x]) return f[x];
    for (int i = 1; i * i <= x; i++) {
        if (x % i) continue;
        if (i * i == x) f[x]++;
        else f[x] += 2;
    }
    return f[x];
}

void update(int l, int r, int step)
{
    if (t[step].l == l && t[step].r == r && t[step].fin)
        return;
    if (t[step].l == t[step].r)
    {
        int temp = t[step].sum;
        t[step].sum = solve(t[step].sum);
        if (t[step].sum == temp)
            t[step].fin = 1;
        return;
    }
    else if (t[step].l == l && t[step].r == r && !t[step].fin)
    {
        int mid = (l + r) / 2;
        update(l, mid, step * 2), update(mid + 1, r, step * 2 + 1);
        push_up(step);
        return;
    }
    int mid = (t[step].l + t[step].r) / 2;
    if (r <= mid)
        update(l, r, step * 2);
    else if (l > mid)
        update(l, r, step * 2 + 1);
    else
        update(l, mid, step * 2), update(mid + 1, r, step * 2 + 1);
    push_up(step);
}
long long query(int l, int r, int step)
{
    if (l == t[step].l && r == t[step].r)
        return t[step].sum;
    int mid = (t[step].l + t[step].r) / 2;
    if (r <= mid)
        return query(l, r, step * 2);
    else if (l > mid)
        return query(l, r, step * 2 + 1);
    else
        return query(l, mid, step * 2) + query(mid + 1, r, step * 2 + 1);
}
void build(int l, int r, int step)
{
    t[step].l = l, t[step].r = r, t[step].sum = 0;
    t[step].fin = 0;
    if (l == r)
    {
        scanf("%d", &t[step].sum);
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, step * 2);
    build(mid + 1, r, step * 2 + 1);
    push_up(step);
}
void debug(int step)
{
    if (t[step].l == t[step].r)
    {
        cout << t[step].sum << " ";
        return;
    }
    debug(step * 2);
    debug(step * 2 + 1);
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2)
    {
        memset(f,0,sizeof(f));
        build(1, n, 1);
        for (int i = 0; i < m; i++)
        {
            int op, l, r;
            scanf("%d%d%d", &op, &l, &r);
            if (op == 1)
                update(l, r, 1);
            else
                printf("%lld\n", query(l, r, 1));
            //debug(1);
            //cout << endl;
        }
    }
}