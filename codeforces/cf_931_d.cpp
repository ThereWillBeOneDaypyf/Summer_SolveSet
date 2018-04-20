#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

vector<int> G[N];
map<int,int> cnt;

void init()
{
  for(int i = 0;i < N;i ++)
    G[i].clear();
  cnt.clear();
}
void dfs(int u,int d)
{
  cnt[d] ++;
  for(auto v : G[u])
    dfs(v, d + 1);
}

int main()
{
  int n;
  while(cin >> n)
  {
    init();
    int ans = 0;
    for(int i = 2;i <= n;i ++)
    {
      int p;
      cin >> p;
      G[p].push_back(i);
    }
    dfs(1,0);
    for(auto temp : cnt)
    {
      if(temp.second % 2)
        ans ++;
    }
    cout << ans << endl;
  }
}