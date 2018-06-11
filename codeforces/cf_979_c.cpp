#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

vector<int> G[N];

long long sz[N];
bool inpath[N];
int tx,ty;
void init()
{
  for(int i =0;i < N;i ++)
    G[i].clear();
  memset(inpath,0,sizeof(inpath));
}

bool dfs(int u,int fa)
{
  sz[u] = 1;
  int flag = (u == ty);
  for(auto v : G[u])
  {
    if(v == fa)
      continue;
    flag |= dfs(v,u);
    sz[u] += sz[v];
  }
  inpath[u] = flag;
  return flag;
}


int main()
{
  int n;
  while(cin >> n >> tx >> ty)
  {
    init();
    for(int i = 1;i < n;i ++)
    {
      int u,v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(tx,tx);
    long long ans = 1LL * n * (n - 1);
    long long s = sz[tx];
    for(auto v : G[tx])
    {
      if(inpath[v])
        s -= sz[v];
    }
    // cout << s << " " << sz[ty] << endl;
    ans -= s * sz[ty];
    cout << ans << endl;
  }
}