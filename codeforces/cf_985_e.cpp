#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 8;

struct Tree
{
  int l,r;
  bool f;
}t[N * 4];

void push_up(int step)
{
  t[step].f = t[step * 2].f | t[step * 2 + 1].f;
}

void build(int l,int r,int step)
{
  t[step].l = l, t[step].r = r;
  t[step].f = 0;
  if(l == r)
    return;
  int mid = (t[step].l + t[step].r) / 2;
  build(l,mid,step * 2);
  build(mid + 1,r, step * 2 + 1);
}

void update(int x,int step)
{
  if(t[step].l == t[step].r)
  {
    t[step].f = 1;
    return;
  }
  int mid = (t[step].l + t[step].r) /  2;
  if(x <= mid)
    update(x,step * 2);
  else update(x,step * 2 + 1);
  push_up(step);
}

bool query(int l,int r,int step)
{
  if(l == t[step].l && r == t[step].r)
    return t[step].f;
  int mid = (t[step].l + t[step].r) / 2;
  if(r <= mid)
    return query(l, r, step * 2);
  else if(l > mid)
    return query(l,r,step * 2 + 1);
  else return query(l,mid,step * 2) | query(mid + 1,r,step * 2 + 1);
}

int a[N];

int main()
{
  int n,k,d;
  while(cin >> n >> k >> d)
  {
    for(int i = 1;i <= n;i ++)
      cin >> a[i];
    sort(a + 1,a + 1 + n);
    build(1,n,1);
    int flag = 0;
    for(int i = 1;i <= n;i ++)
    {
      int get_pos = lower_bound(a + 1,a + 1 + n,a[i] - d) - a;
      int lit_pos = i - k + 1;
      if(get_pos > lit_pos)
        continue;
      if(i == n)
      {
        flag = query(get_pos,lit_pos,1);
      }
      update(i + 1,1);
    }
    if(flag)
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}