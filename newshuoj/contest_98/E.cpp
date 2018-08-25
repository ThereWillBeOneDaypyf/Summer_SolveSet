#include<bits/stdc++.h>
using namespace std;

int xdir[4] = {1,0,-1,0};
int ydir[4] = {0,1,0,-1};
int vis[10][10];
int n,m;

void solve(int x,int y)
{
  for(int i = 0;i < 4;i ++)
  {
    int tx = x + xdir[i];
    int ty = y + ydir[i];
    if(tx < 0 || tx >= n || ty < 0 || ty >= m)
      continue;
    vis[tx][ty] = 1;
  }
}

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    cin >> n >> m;
    memset(vis,0,sizeof(vis));
    for(int i = 0;i < n;i ++)
    {
      for(int j = 0;j < m;j ++)
      {
        if(!vis[i][j])
        {
          solve(i,j);
        }
      }
    }
    int ans = 0;
    for(int i = 0;i < n;i ++)
    {
      for(int j = 0;j < m;j ++)
      {
        if(!vis[i][j])
          ans ++;
      }
    }
    cout << ans << endl;
  }
}