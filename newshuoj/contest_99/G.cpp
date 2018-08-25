#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<int> G[N];
long long val[N][3];
long long dp[N][3];

void init()
{
  memset(dp,0,sizeof(dp));
  for (int i = 0; i < N; i++)
    G[i].clear();
}

void add_edge(int u, int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}

void dfs(int u, int fa)
{
  for (auto v : G[u])
  {
    if (v == fa)
      continue;
    dfs(v, u);
  }
  for (int i = 0; i < 3; i++)
  {
    dp[u][i] = val[u][i];
    for (auto v : G[u])
    {
      long long son_max = -1;
      for (int j = 0; j < 3; j++)
      {
        if (j == i)
          continue;
        son_max = max(dp[v][j], son_max);
      }
      dp[u][i] += son_max;
    }
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n;
    scanf("%d", &n);
    init();
    for (int i = 1; i < n; i++)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      add_edge(u, v);
    }
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < 3; j++)
        scanf("%lld", &val[i][j]);
    dfs(1, 1);
    printf("%lld\n", max(dp[1][0], max(dp[1][1], dp[1][2])));
  }
}