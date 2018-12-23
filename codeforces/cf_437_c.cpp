#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;

int vis[N];
int a[N];
vector<int> G[N];
int main()
{
  int n,m;
  while(cin >> n >> m)
  {
    for(int i = 0;i < N;i ++)
      G[i].clear();
    memset(vis,0,sizeof(vis));
    vector<int> v;
    for(int i = 1;i <= n;i ++)
    {
      v.push_back(i);
      cin >> a[i];
    }
    for(int i = 0;i < m;i ++)
    {
      int u,vv;
      cin >> u >> vv;
      G[u].push_back(vv);
      G[vv].push_back(u);
    }
    sort(v.begin(),v.end(),[](int id_i,int id_j) { return a[id_i] > a[id_j];});
    long long ans = 0;
    for(auto u : v)
    {
      vis[u] = 1;
      for(auto vv : G[u])
      {
        if(!vis[vv])
        {
          ans += a[vv];
        }
      }
    }
    cout << ans << endl;
  }
}