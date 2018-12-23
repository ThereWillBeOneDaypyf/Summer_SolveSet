#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

vector<int> G[N];
vector<int> E[N];
int Index = 0;
int cnt = 0;
int instack[N],belong[N];
int dfn[N],low[N];
stack<int> st;
long long min_cost[N];
long long cost[N];
int n;

void init()
{
  for(int i = 0;i < N;i ++)
    G[i].clear(),E[i].clear();
  Index = 0;
  cnt = 0;
  memset(instack,0,sizeof(instack));
  while(!st.empty())
    st.pop();
}

void tarjan(int u)
{
  dfn[u] = low[u] = ++ Index;
  st.push(u);
  instack[u] = 1;
  for(auto v : G[u])
  {
    if(!dfn[v])
    {
      tarjan(v);
      low[u] = min(low[u],low[v]);
    }
    else if(instack[v])
      low[u] = min(low[u],dfn[v]);
  }
  int x;
  if(dfn[u] == low[u])
  {
    cnt ++;
    min_cost[cnt] = cost[st.top()];
    do{
      x = st.top();
      st.pop();
      instack[x] = 0;
      min_cost[cnt] = min(min_cost[cnt],cost[x]);
      belong[x] = cnt;
    }while(x != u);
  }
}

void solve()
{
  for(int i = 1;i <= n;i ++)
    if(!dfn[i])
      tarjan(i);
}

int vis[N];
int in[N];
long long dp[N];

void dfs(int u)
{
  dp[u] = min_cost[u];
  long long res = 0;
  for(auto v : E[u])
  {
    dfs(v);
    res += dp[v];
  }
  if(res)
    dp[u] = min(res,dp[u]);
}


int main()
{
  while(cin >> n)
  {
    init();
    for(int i = 1;i <= n;i ++)
      cin >> cost[i];
    for(int i = 1;i <= n;i ++)
    {
      int v;
      cin >> v;
      G[i].push_back(v);
    }
    solve();
    memset(in,0,sizeof(in));
    for(int i = 1;i <= n;i ++)
    {
      for(auto v : G[i])
      {
        if(belong[i] != belong[v])
        {
          E[belong[i]].push_back(belong[v]);
          in[belong[i]] ++;
        }
      }
    }
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    long long ans = 0;
    for(int i = 1;i <= cnt;i ++)
    {
      if(!in[i])
      {
        dfs(i);
        ans += dp[i];
      }
    }
    cout << ans << endl;
  }
}