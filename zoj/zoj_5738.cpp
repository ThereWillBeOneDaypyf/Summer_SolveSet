#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > Map;
vector<vector<bool> > vis;
int n,m;
int sx,sy,ex,ey;
int xdir[4] = {0,1,0,-1};
int ydir[4] = {1,0,-1,0};

struct Node
{
  int x,y;
  int step;
};

int judge(int x,int y)
{
  int flag = abs(x - sx) + abs(y - sy);
  flag %= 2;
  flag += 2;
  flag %= 2;
  flag = flag ^ Map[x][y];
  return !flag;
}

int bfs()
{
  vis.clear();
  for(int i = 0;i < n;i ++)
  {
    vector<bool> tempj;
    for(int j = 0;j < m;j ++)
    {
      tempj.push_back(false);
    }
    vis.push_back(tempj);
  }
  queue<Node> q;
  q.push((Node){sx,sy,0});
  while(!q.empty())
  {
    auto temp = q.front();
    int x = temp.x;
    int y = temp.y;
    int step = temp.step;
    q.pop();
    if(vis[x][y])
      continue;
    if(x == ex && y == ey)
      return step;
    vis[x][y] = 1;
    for(int i = judge(x,y);i < 4;i += 2)
    {
      int tx = x + xdir[i];
      int ty = y + ydir[i];
      if(tx < 0 || tx >= n || ty < 0 || ty >= m)
        continue;
      if(vis[tx][ty])
        continue;
      q.push((Node){tx,ty,step + 1});
    }
  }
  return -1;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    cin >> n >> m;
    Map.clear();
    for(int i = 0;i < n;i ++)
    {
      vector<int> tempj;
      for(int j = 0;j < m; j++)
      {
        int x;
        cin >> x;
        tempj.push_back(x);
      }
      Map.push_back(tempj);
    }
    cin >> sx >> sy >> ex >> ey; 
    sx --, sy --, ex --, ey --;
    cout << bfs() << endl;
  }
}