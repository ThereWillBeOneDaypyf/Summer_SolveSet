#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

struct Tree
{
    int lt, rt;
    long long vis;
    long long sum;
} t[N * 50];

int root[N];

int cnt = 0;

void init_node(int x)
{
    t[x].lt = t[x].rt = t[x].vis = t[x].sum = 0;
}

int new_node()
{
    cnt ++;
    init_node(cnt);
    return cnt;
}

void cp(const Tree& lhs, Tree& rhs)
{
    rhs.lt = lhs.lt, rhs.rt = lhs.rt;
    rhs.sum = lhs.sum, rhs.vis = lhs.vis;
}

void init()
{
    cnt = 0;
    memset(root, 0, sizeof(root));
}

void build(int l, int r, int &x)
{
    x = new_node();
    if (l == r)
    {
        scanf("%lld", &t[x].sum);
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, t[x].lt);
    build(mid + 1, r, t[x].rt);
    t[x].sum = t[t[x].lt].sum + t[t[x].rt].sum;
}

void update(int l, int r, int ql, int qr, int val, int x, int& y)
{
    y = new_node();
    cp(t[x], t[y]);
    t[y].sum += 1LL * val * (qr - ql + 1);
    if (l == ql && r == qr)
    {
        t[y].vis += val;
        return;
    }
    int mid = (l + r) / 2;
    if (qr <= mid)
        update(l, mid, ql, qr, val, t[x].lt, t[y].lt);
    else if (ql > mid)
        update(mid + 1, r, ql, qr, val, t[x].rt, t[y].rt);
    else update(l, mid, ql, mid, val, t[x].lt, t[y].lt), update(mid + 1, r, mid + 1, qr, val, t[x].rt, t[y].rt);
}

long long query(int l, int r, int ql, int qr, int x)
{
    if (l == ql && r == qr)
        return t[x].sum;
    long long ret = (qr - ql + 1) * t[x].vis;
    int mid = (l + r) / 2;
    if (qr <= mid)
        return ret + query(l, mid, ql, qr, t[x].lt);
    else if (ql > mid)
        return ret + query(mid + 1, r, ql, qr, t[x].rt);
    else return ret + query(l, mid, ql, mid, t[x].lt) + query(mid + 1, r, mid + 1, qr, t[x].rt);
}
int main()
{
    int x, L, R;
    int now;
    char ch[3];

    bool f = false;
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        if (f) puts("");
        else f = true;
        init();
        build(1, n, root[0]);
        int version = 0;
        while (m--)
        {
            scanf("%s", ch);
            if (ch[0] == 'C')
            {
                scanf("%d%d%d", &L, &R, &x);
                version ++;
                update(1, n, L, R, x, root[version - 1], root[version]);
            }
            else if (ch[0] == 'Q')
            {
                scanf("%d%d", &L, &R);
                printf("%lld\n", query(1, n, L, R, root[version]));
            }
            else if (ch[0] == 'H')
            {
                scanf("%d%d%d", &L, &R, &x);
                printf("%lld\n", query(1, n, L, R, root[x]));
            }
            else if (ch[0] == 'B')
            {
                scanf("%d", &version);
            }
        }
    }

    return 0;
}毛