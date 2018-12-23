#include<bits/stdc++.h>
using namespace std;

struct Edge
{
  int u,v;
  int d;
  bool operator <(const Edge& rhs) const
  {
    return d < rhs.d;
  }
};

char Map[11][11][1001];

vector<Edge> e;
vector<int> G[1001];
int fa[1001];
int n,m,k,w;

void init()
{
  for(int i = 0;i < 1001;i ++)
    G[i].clear(),fa[i] = i;
  e.clear();
}

int find(int x)
{
  if(fa[x] != x)
    fa[x] = find(fa[x]);
  return fa[x];
}

void merge(int u,int v)
{
  u = find(u), v = find(v);
  if(fa[u] != fa[v])
    fa[u] = fa[v];
}

int solve(int u,int v)
{
  int cnt = 0;
  for(int i = 0;i < n;i ++)
  {
    for(int j = 0;j < m;j ++)
    {
      if(Map[i][j][u] != Map[i][j][v])
        cnt ++;
    }
  }
  return cnt * w;
}

int kruskal()
{
  sort(e.begin(),e.end());
  int ans = 0;
  merge(0,1);
  ans += n * m;
  G[0].push_back(1);
  G[1].push_back(0);
  for(auto temp_e : e)
  {
    int u = temp_e.u, v = temp_e.v, d = temp_e.d;
    // cout << u <<  " " << v << " " << find(u) << " " << find(v) << endl;
    if(find(u) == find(v))
      continue;
    merge(u,v);
    ans += d;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  return ans;
}

void dfs(int u,int f)
{
  for(auto v : G[u])
  {
    if(v == f)
      continue;
    cout << v << " " << u << endl;
    dfs(v,u);
  }
}

int main()
{
  string s;
  while(cin >> n >> m >> k >> w)
  {
    init();
    for(int i = 1;i <= k;i ++)
    {
      for(int j = 0;j < n;j ++)
      {
        cin >> s;
        for(int x = 0;x <m;x ++)
        {
          Map[j][x][i] = s[x];
        }
      }
    }
    for(int i = 1;i <= k;i ++)
      e.push_back({0,i,n * m});
    for(int i = 1;i <= k;i ++)
      for(int j = i + 1;j <= k;j ++)
        e.push_back({i,j,solve(i,j)});
    cout << kruskal() << endl;
    dfs(0,0);
  }
}