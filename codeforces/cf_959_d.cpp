#include<bits/stdc++.h>
using namespace std;

const int N = 1500000;

bool vis[N];
vector<int> G[N];
set<int> s;
int main()
{
  int n;
  while(scanf("%d",&n) == 1)
  {
    s.clear();
    for(int i = 0;i < N;i ++)
      G[i].clear();
    memset(vis,0,sizeof(vis));
    for(int i = 2;i < N;i++)
    {
      s.insert(i);
      if(!vis[i])
      {
        for(int j = i;j < N;j += i)
        {
          vis[i] = 1;
          G[j].push_back(i);
        }
      }
    }
    bool eq = 1;
    memset(vis,0,sizeof(vis));
    for(int i = 0;i < n;i ++)
    {
      int x;
      scanf("%d",&x);
      int cur = *s.begin();
      if(eq)
      {
        cur = *s.lower_bound(x);
        if(cur != x)
          eq = 0;
      }
      printf("%d ",cur);
      for(int temp : G[cur])
      {
        for(int j = temp;j < N;j += temp)
        {
          if(!vis[j])
          {
            vis[j] = 1;
            s.erase(j);
          }
        }
      }
    }
  }
}