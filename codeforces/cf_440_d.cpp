#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

const int N = 1e3;

vector<pair<int, int>> G[N];
int dp[N][N];
vector<int> path[N][N];
int sz[N];
int n, k;

void init()
{
  for (int i = 0; i < N; i++)
    G[i].clear();
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    {
      path[i][j].clear();
      dp[i][j] = INF;
    }
}

void add_edge(int u, int v, int Index)
{
  G[u].push_back(make_pair(v, Index));
  G[v].push_back(make_pair(u, Index));
}

void dfs_sz(int u, int f)
{
  sz[u] = 1;
  for (auto temp : G[u])
  {
    int v = temp.first;
    if (v == f)
      continue;
    dfs_sz(v, u);
    sz[u] += sz[v];
  }
}

void dfs(int u, int fa, int last_id)
{
  dp[u][0] = 0;
  for (auto temp : G[u])
  {
    int v = temp.first;
    int id = temp.second;
    if (v == fa)
      continue;
    dfs(v, u, id);
    for (int i = sz[u]; i >= 0; i--)
    {
      for (int j = 0; j <= min(sz[v], i); j++)
      {
        if (dp[u][i] > dp[u][i - j] + dp[v][j])
        {
          dp[u][i] = dp[u][i - j] + dp[v][j];
          path[u][i] = path[u][i - j];
          for(auto id : path[v][j])
            path[u][i].push_back(id);
        }
      }
    }
  }
  if (sz[u] != n)
  {
    path[u][sz[u]].clear();
    path[u][sz[u]].push_back(last_id);
    dp[u][sz[u]] = 1;
  }

}

void out_ans(int u,int fa,int tar)
{
  for(auto temp : G[u])
  {
    int v = temp.first;
    int id = temp.second;
    if(v == fa)
      continue;
    if(v == tar)
    {
      cout << id;
      return;
    }
    out_ans(v,u,tar);
  }
}

int main()
{
  while (cin >> n >> k)
  {
    init();
    for (int i = 1; i < n; i++)
    {
      int u, v;
      cin >> u >> v;
      add_edge(u, v, i);
    }
    dfs_sz(1, 1);
    dfs(1, 1, 0);
    dp[1][n] = 0;
    int ans_root = 1;
    int ans = dp[1][n - k];
    // for(int i = 1;i <= n;i ++)
    // {
    //   cout << " ***** id : " << i << endl;
    //   for(int j = 0;j <= sz[i]; j++)
    //   {
    //     cout << " * * del : " << j <<  " : ";
    //     for(auto id : path[i][j])
    //       cout << id << " ";
    //     cout << endl;
    //   }
    // }
    for (int i = 2; i <= n; i++)
    {
      if (sz[i] >= k)
      {
        if (ans > dp[i][sz[i] - k] + 1)
        {
          ans_root = i;
          ans = dp[i][sz[i] - k] + 1;
        }
      }
    }
    cout << ans << endl;
    for (auto v : path[ans_root][sz[ans_root] - k])
      cout << v << " ";
    if(ans_root != 1)
      out_ans(1,1,ans_root);
    cout << endl;
  }
}