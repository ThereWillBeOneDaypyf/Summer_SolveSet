#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e4 + 7;
const int M = 1e6 + 7;

vector<int>G[N];
bool vis[M];
int pre[M];
queue<int> q;

void init()
{
  for(int i = 0;i < N;i ++)
    G[i].clear();
}

void add_edge(int u,int v)
{
  G[u].push_back(v);
}

bool dfs(int u)
{
  for(int i = 0;i < G[u].size();i ++)
  {
    int v = G[u][i];
    if(!vis[v])
    {
      vis[v] = 1;
      q.push(v);
      if(pre[v] == -1 || dfs(pre[v]))
      {
        pre[v] = u;
        return true;
      }
    }
  }
  return false;
}

int solve()
{
  int cnt = 0;
  memset(pre,-1,sizeof(pre));
  for(int i = 1;i <= 1e4;i ++)
  {
    while(!q.empty())
    {
      vis[q.front()] = false;
      q.pop();
    }
    if(dfs(i))
      cnt ++;
    else break;
  }
  return cnt;
}

int main()
{
  int n;
  while(scanf("%d",&n) == 1)
  {
    init();
    for(int i = 1;i <= n;i ++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      add_edge(u,i);
      add_edge(v,i);
    }
    printf("%d\n",solve());
  }
}