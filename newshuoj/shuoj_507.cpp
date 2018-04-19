#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
long long ans = 0;
vector<int> G[N];
int cnt[N];
vector<int> v;
vector<int> y[N];
int vis[N];

void init_vis()
{
  memset(vis,0,sizeof(vis));
  for(int i = 2;i < N;i ++)
  {
    if(vis[i])
      continue;
    for(int j = 2;j * i < N;j ++)
    {
      vis[i * j] = 1; 
    }
  }
}

void init()
{
  for(int i = 0;i < N;i ++)
    G[i].clear(),y[i].clear();
  ans = 0;
  memset(cnt,0,sizeof(cnt));
  v.clear();
}

void add_edge(int u,int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}

void solve_y()
{
  for(int i = 1;i < v.size(); i++)
  {
    for(int j = 1;j < sqrt(v[i]);j ++)
    {
      if(v[i] % j)
        continue;
      if(vis[j])
        y[i].push_back(j);
      if(vis[v[i] / j])
        y[i].push_back(v[i] / j);
    }
    int mid = sqrt(v[i]);
    if(mid * mid == v[i])
    {
      if(vis[mid])
        y[i].push_back(mid);
    }
  }
}

void dfs(int u,int fa)
{
  int init_cnt = 0;
  for(auto x : y[u])
    init_cnt += cnt[x];
  cnt[v[u]] ++;
  for(auto v : G[u])
  {
    if(v == fa)
      continue;
    dfs(v,u);
  }
  int all_cnt = 0;
  for(auto x : y[u])
    all_cnt += cnt[x];
  int real_cnt = all_cnt - init_cnt;
  ans += 1LL * u * real_cnt;
  ans %= MOD;
}

int main()
{
  ios :: sync_with_stdio(false);
  int T;
  init_vis();
  cin >> T;
  while(T--)
  {
    int n,r;
    cin >> n >> r;
    init();
    for(int i = 1;i < n;i ++)
    {
      int u,v;
      cin >> u >> v;
      add_edge(u,v);
    }
    v.push_back(-1);
    for(int i = 1;i <= n;i ++)
    {
      int x;
      cin >> x;
      v.push_back(x);
    }
    solve_y();
    dfs(r,r);
    cout << ans << endl;
  } 
}