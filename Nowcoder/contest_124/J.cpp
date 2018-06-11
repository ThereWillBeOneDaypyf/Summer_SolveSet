#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
const long long INF = 1e18;

struct Tree
{
  int l,r;
  long long Min;
  long long Max;
}t[N * 4];

void push_up(int step)
{
  t[step].Min = min(t[step * 2].Min,t[step * 2 + 1].Min);
  t[step].Max = max(t[step * 2].Max,t[step * 2 + 1].Max);
}

void build(int l,int r,int step)
{
  t[step].l = l, t[step].r = r;
  t[step].Min = INF;
  t[step].Max = -INF;
  if(l == r)
  {
    scanf("%lld",&t[step].Min);
    t[step].Max = t[step].Min;
    return;
  }
  int mid = (l + r) / 2;
  build(l,mid,step * 2);
  build(mid + 1,r, step * 2 + 1);
  push_up(step);
}

void update(int x,int step)
{
  if(t[step].l == t[step].r)
  {
    t[step].Min ++;
    t[step].Max ++;
    return;
  }
  int mid = (t[step].l + t[step].r) / 2;
  if(x <= mid)
    update(x,step * 2);
  else update(x,step * 2 + 1);
  push_up(step);
}

int query(int val,int step)
{
  if(t[step].l == t[step].r)
    return t[step].l;
  if(t[step * 2].Max >= val)
    return query(val,step * 2);
  else 
    return query(val,step * 2 + 1);
}

int main()
{
  int n,q;
  while(scanf("%d%d",&n,&q) == 2)
  {
    build(1,n,1);
    for(int i = 0;i < q;i ++)
    {
      int tar;
      scanf("%d",&tar);
      if(t[1].Max < tar)
      {
        printf("are you ok\n");
      }
      else
      {
        int id = query(tar,1);
        id --;
        printf("%d\n",id);
        if(id)
          update(id,1);
      }
    }
  }
}