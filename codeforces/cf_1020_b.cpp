#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int vis[N];
int p[N];

void init()
{
}


int dfs(int u)
{
  if(vis[u])
    return u;
  vis[u] = 1;
  dfs(p[u]);
}

int main()
{
  int n;
  while(cin >> n)
  {
    for(int i = 1;i <= n;i ++)
      cin >> p[i];
    for(int i = 1;i <= n;i ++)
    {
      memset(vis,0,sizeof(vis));
      cout << dfs(i) << " ";
    }
    cout << endl;
  }
}
