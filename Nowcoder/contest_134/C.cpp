#include<bits/stdc++.h>
using namespace std;

const int N  = 1e3 + 7;

int xdir[4] = {0,1,0,-1};
int ydir[4] = {1,0,-1,0};
bool vis[N][N];
int n,m;

bool judge(int x,int y)
{
  if(x > n || x <= 0 || y <= 0 || y > n)
    return false;
  if(vis[x][y])
    return false;
  int cnt = 0;
  for(int i = 0;i < 4;i ++)
  {
    int tx = x + xdir[i];
    int ty = y + ydir[i];
    if(x <= 0 || x > n || y <= 0 || y > n)
      continue;
    if(vis[tx][ty])
      cnt ++;
  }
  return cnt >= 2;
}

void debug()
{
  for(int i = 1;i <= n;i ++)
  {
    for(int j = 1;j <= n;j ++)
      cout << vis[i][j];
    cout << endl;
  }
}

bool bfs()
{
  queue<pair<int,int> > q;
  memset(vis,0,sizeof(vis));
  for(int i = 0;i < m;i ++)
  {
    int x,y;
    cin >> x >> y;
    q.push(make_pair(x,y));
    vis[x][y] = 1;
  }
  // debug();
  while(!q.empty())
  {
    auto temp = q.front();
    q.pop();
    for(int i = 0;i < 4;i ++) 
    {
      int tx = temp.first + xdir[i];
      int ty = temp.second + ydir[i];
      if(judge(tx,ty))
      {
        q.push(make_pair(tx,ty));
        vis[tx][ty] = 1;
      }
    }
    // debug();
  }
  for(int i = 1;i <= n;i ++)
  {
    for(int j = 1;j <= n;j ++)
    {
      if(!vis[i][j])
        return false;
    }
  }
  return true;
}

int main()
{
  while(cin >> n >> m)
  {
    if(bfs())
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}