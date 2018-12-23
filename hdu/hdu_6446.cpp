#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
vector<pair<int,int> > G[N];
int sz[N];
int n;
long long ans = 0;

void init()
{
  memset(sz,0,sizeof(sz));
  for(int i = 0;i < N;i ++)
    G[i].clear();
}

void dfs(int u,int fa)
{
  sz[u] = 1;
  for(auto temp : G[u])
  {
    int v = temp.first;
    if(v == fa)
      continue;
    dfs(v,u);
    sz[u] += sz[v];
  }
  for(auto temp : G[u])
  {
    int v = temp.first;
    int d = temp.second;
    if(v == fa)
      continue;
    ans += 1LL * d * sz[v] * (n - sz[v]);
    ans %= MOD;
  }
}

int main()
{
  while(scanf("%d",&n) == 1)
  {
    init();
    for(int i = 1;i < n;i ++)
    {
      int u,v,d;
      scanf("%d%d%d",&u,&v,&d);
      G[u].push_back(make_pair(v,d));
      G[v].push_back(make_pair(u,d));
    }
    ans = 0;
    dfs(1,1);
    for(int i = 1;i < n;i ++)
    {
      ans *= 1LL * i;
      ans %= MOD;
    }
    ans *= 2;
    ans %= MOD;
    printf("%lld\n",ans);
  }
}