#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int fa[N];
int deg[N];
int status[N];
void init()
{
  memset(deg,0,sizeof(deg));
  for(int i = 0;i < N;i ++)
    fa[i] = i;
}

int find(int x)
{
  if(fa[x] != x)
    fa[x] = find(fa[x]);
  return fa[x];
}

void merge(int a,int b)
{
  a = find(a);
  b = find(b);
  if(fa[a] != fa[b])
    fa[a] = fa[b];
}


int main()
{
  int n,m;
  while(cin >> n >> m)
  {
    init();
    for(int i = 1;i <= m;i ++)
    {
      int u,v;
      cin >> u >> v;
      deg[u] ++;
      deg[v] ++;
      merge(u,v);
    }
    memset(status,-1,sizeof(status));
    for(int i = 1;i <= n;i ++)
    {
      int anc = find(i);
      if(status[anc] == 0)
        continue;
      if(deg[i] == 2)
      {
        if(status[anc] == -1)
          status[anc] = 1;
      }
      else 
      {
        status[anc] = 0;
      }
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++)
      if(status[i] == 1)
        ans ++;
    cout << ans << endl;
  }
}