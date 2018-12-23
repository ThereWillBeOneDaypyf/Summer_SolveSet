#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

struct Node
{
  long double x,y;
  long double r;
}v[N];

vector<pair<int,long double> > G[N];


void init()
{
  for(int i = 0;i < N;i ++)
    G[i].clear();
}
int n;
long double a,b,c1,c2;

void link_circle(int id)
{
  long double d = abs(a * v[id].x + b * v[id].y + c1) / sqrt(a * a + b * b);
  G[0].push_back(make_pair(id,max((long double)0,d - v[id].r)));
  d = abs(a * v[id].x + b * v[id].y + c2) / sqrt(a * a + b * b);
  G[id].push_back(make_pair(n + 1,max((long double)0,d - v[id].r)));
}

void link_point(int x,int y)
{
  long double d = (v[x].x - v[y].x) * (v[x].x - v[y].x) + (v[x].y - v[y].y) * (v[x].y - v[y].y);
  d = sqrt(d);
  d -= (v[x].r + v[y].r);
  G[x].push_back(make_pair(y,max((long double)0,d)));
  //G[y].push_back(make_pair(x,max((long double)0,d)));
}

int vis[N];
long double dis[N];


long double spfa()
{
  queue<int> q;
  q.push(0);
  memset(vis,0,sizeof(vis));
  for(int i = 0;i <= n + 1;i ++)
    dis[i] = 1e18;
  dis[0] = 0;
  vis[0] = 1;  
  while(!q.empty())
  {
    auto u = q.front();
    q.pop();
    vis[u] = 0;
    for(auto temp : G[u])
    {
      int v = temp.first;
      long double d = temp.second;
      if(dis[u] + d < dis[v])
      {
        dis[v] = dis[u] + d;
        if(!vis[v])
        {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
  }
  return dis[n + 1];
}

int main()
{
  ios :: sync_with_stdio(false);
  while(cin >> n >> a >> b >> c1 >> c2)
  {
    init();
    long double temp = abs(c1 - c2) / sqrt(a * a + b * b);
    G[0].push_back(make_pair(n + 1,temp));
    for(int i = 1;i <= n;i ++)
    {
      cin >> v[i].x >> v[i].y >> v[i].r;
      link_circle(i);
    }
    for(int i = 1;i <= n;i ++)
    {
      for(int j = 1;j <= n;j ++)
      {
        if(i == j)
          continue;
        link_point(i,j);
      }
    }
    // for(int i = 0; i<= n + 1;i ++)
    // {
    //   cout << i << " ------->  " << endl;
    //   for(auto temp : G[i])
    //     cout << temp.first << " " << temp.second << endl;
    // }
    cout << spfa() << endl;
  }
}