#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

vector<pair<int,long long> > G[N  * 4];
int id[N * 4][2];

int cnt = 0;

void init(int n)
{
  cnt = n;
  memset(id,0,sizeof(id));
  for(int i = 0;i < N * 4;i ++)
    G[i].clear();
}

void add_edge(int u,int v,long long w)
{
  G[u].push_back(make_pair(v,w));
}

void build(int l,int r,int step,int ty)
{
  id[step][ty] = ++ cnt;
  if(l == r)
  {
    if(!ty)
    {
      G[id[step][ty]].push_back(make_pair(l,0));
    }
    else
    {
      G[l].push_back(make_pair(id[step][ty],0));
    }
    return;
  }
  int mid = (l + r) / 2;
  build(l,mid,step * 2,ty);
  build(mid + 1,r,step * 2 + 1,ty);
  if(!ty)
  {
    add_edge(id[step][ty],id[step * 2][ty],0);
    add_edge(id[step][ty],id[step * 2 + 1][ty],0);
  }
  else
  {
    add_edge(id[step * 2][ty],id[step][ty],0);
    add_edge(id[step * 2 + 1][ty],id[step][ty],0);
  }
}

void update(int ql,int qr,int l,int r,int tar,long long val,int step,int ty)
{
  if(l == ql && r == qr)
  {
    if(!ty)
    {
      add_edge(tar,id[step][ty],val);
    }
    else add_edge(id[step][ty],tar,val);
    return;
  }
  int mid = (l + r) / 2;
  if(qr <= mid)
    update(ql,qr,l,mid,tar,val,step * 2,ty);
    // update(l,mid,ql,qr,tar,val,step * 2,ty);
  else if(ql > mid)
    update(ql,qr,mid + 1,r,tar,val,step * 2 + 1,ty);
    // update(mid + 1,r,ql,qr,tar,val,step * 2 + 1,ty);
  // else update(l,mid,ql,mid,tar,val,step * 2,ty), update(mid + 1,r,mid + 1,qr,tar,val,step * 2 + 1,ty);
  else update(ql,mid,l,mid,tar,val,step * 2,ty),update(mid + 1,qr,mid + 1,r,tar,val,step * 2 + 1,ty);
}

int vis[N  * 4];
long long dis[N * 4];

void spfa(int s)
{
  queue<int> q;
  memset(vis,0,sizeof(vis));
  for(int i  = 0;i < N * 4;i ++)
    dis[i] = 1e18;
  dis[s] = 0;
  vis[s] = 1;
  q.push(s);
  while(!q.empty())
  {
    auto u  = q.front();
    q.pop();
    vis[u] = 0;
    for(auto temp : G[u])
    {
      int v = temp.first;
      long long d = temp.second;
      if(dis[v] > dis[u] + d)
      {
        dis[v] = dis[u] + d;
        if(!vis[v])
        {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
}

int main()
{
  int n,q,s;
  while(scanf("%d%d%d",&n,&q,&s) == 3)
  {
    init(n);
    build(1,n,1,0);
    build(1,n,1,1);
    for(int i = 0;i < q;i ++)
    {
      int op;
      scanf("%d",&op);
      if(op == 1)
      {
        int u,v;
        long long val;
        scanf("%d%d%lld",&u,&v,&val);
        add_edge(u,v,val);
      }
      else 
      {
        int l,r,tar;
        long long val;
        scanf("%d%d%d%lld",&tar,&l,&r,&val);
        if(op == 2)
        {
          update(l,r,1,n,tar,val,1,0);
        }
        else 
        {
          update(l,r,1,n,tar,val,1,1);
        }
      }
    }
    spfa(s);
    for(int i = 1;i <= n;i ++)
    {
      if(i != 1)
        printf(" ");
      printf("%lld",(dis[i] >= 1e18) ? -1 : dis[i]);
    }
    printf("\n");
  }
}