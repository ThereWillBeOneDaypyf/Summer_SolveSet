#include<bits/stdc++.h>
using  namespace std;

const int N = 1e5 + 7;

int sz[N];
vector<int> G[N];

void init()
{
  for(int i = 0;i < N;i ++)
    G[i].clear();
}

void dfs(int u,int fa)
{
  sz[u] = 1;
  for(auto v : G[u])
  {
    if(v == fa)
      continue;
    dfs(v,u);
    sz[u] ^= sz[v];
  }
}

int main()
{
  int n;
  while(cin >> n)
  {
    init();
    for(int i = 1;i < n;i ++)
    {
      int u,v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    if(n % 2)
    {
      cout << - 1 << endl;
      continue;
    }
    dfs(1,1);
    int cnt = 0;
    for(int i = 1;i <= n;i ++)
    {
      if(!sz[i])
        cnt ++;
    }
    cout << cnt - 1 << endl;
  }
}