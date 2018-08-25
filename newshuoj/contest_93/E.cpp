#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int sz[N];
int fa[N];

struct Tree
{
  int l,r;
  int sum;
}t[N * 4];

void push_up(int step)
{
  t[step].sum = t[step * 2].sum + t[step * 2 + 1].sum;
}

void build(int l,int r,int step)
{
  t[step].l = l,t[step].r = r;
  t[step].sum = 0;
  if(l == r)
    return;
  int mid = (l + r) / 2;
  build(l,mid, step * 2);
  build(mid + 1,r, step * 2 + 1);
}

void update(int x,int val,int step)
{
  if(t[step].l == t[step].r)
  {
    t[step].sum += val;
    return;
  }
  int mid = (t[step].l + t[step].r) / 2;
  if(x <= mid)
    update(x,val,step * 2);
  else update(x,val,step * 2 + 1);
  push_up(step);
}

int query(int k,int step)
{
  if(t[step].l == t[step].r)
  {
    return t[step].l;
  }
  if(t[step * 2 + 1].sum >= k)
    return query(k,step * 2 + 1);
  else return query(k - t[step * 2 + 1].sum,step * 2);
}

void init(int n)
{
  for(int i = 1;i <= n;i ++)
    sz[i] = 1,fa[i] = i;
  build(1,n,1);
  update(1,n,1);
}

int find(int x)
{
  if(fa[x] != x)
    fa[x] = find(fa[x]);
  return fa[x];
}

void merge(int a,int b)
{
  a = find(a),b = find(b);
  if(fa[a] != fa[b])
  {
    update(sz[fa[a]],-1,1);
    update(sz[fa[b]],-1,1);
    sz[fa[b]] += sz[fa[a]];
    fa[a] = fa[b];
    update(sz[fa[b]],1,1);
  }
}

void debug(int n)
{
  for(int i = 1;i <= n;i ++)
    cout << "fa : " << find(i) << " " << sz[find(i)] << endl;
  // debug_tree(1);
}

int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i = 0;i < m;i ++)
    {
      int op;
      scanf("%d",&op);
      if(!op)
      {
        int a,b;
        scanf("%d%d",&a,&b);
        merge(a,b);
      }
      else
      {
        int k;
        scanf("%d",&k);
        printf("%d\n",query(k,1));
      }
      // debug(n);
    }
  }
}