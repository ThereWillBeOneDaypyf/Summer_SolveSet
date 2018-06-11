#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int dp[N][101];
vector<int> G[N];
int ty[N];
int cnt[N];
int n, m, s, k;

void init()
{
  for (int i = 0; i < N; i++)
    G[i].clear();
  memset(dp, -1, sizeof(dp));
}

void real_bfs(int t)
{
  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    if (ty[i] != t)
      continue;
    q.push(i);
    dp[i][t] = 0;
  }
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (auto v : G[u])
    {
      if (dp[v][t] == -1)
      {
        dp[v][t] = dp[u][t] + 1;
        q.push(v);
      }
      else if (dp[v][t] > dp[u][t] + 1)
      {
        dp[v][t] = dp[u][t] + 1;
        q.push(v);
      }
    }
  }
}

void init_bfs()
{
  for (int i = 1; i <= k; i++)
  {
    real_bfs(i);
  }
}

int bfs(int x)
{
  vector<int> ans;
  for (int i = 1; i <= k; i++)
    ans.push_back(dp[x][i]);
  sort(ans.begin(), ans.end());
  int sum = 0;
  for (int i = 0; i < s; i++)
    sum += ans[i];
  return sum;
}

int main()
{
  while (scanf("%d%d%d%d", &n, &m, &k, &s) == 4)
  {
    init();
    for (int i = 1; i <= n; i++)
    {
      // cin >> ty[i];
      scanf("%d", ty + i);
      dp[i][ty[i]] = 0;
    }
    for (int i = 0; i < m; i++)
    {
      int u, v;
      // cin >> u >> v;
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    init_bfs();
    vector<int> ans;
    for (int i = 1; i <= n; i++)
      ans.push_back(bfs(i));
    for (int i = 0; i < n; i++)
    {
      if (i)
        printf(" ");
      // cout << " ";
      // cout << ans[i];
      printf("%d", ans[i]);
    }
    // cout << endl;
    printf("\n");
  }
}