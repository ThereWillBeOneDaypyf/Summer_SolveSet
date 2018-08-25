#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 7;

int id[N];
vector<int> G[N];
int cnt[N];

void init()
{
  memset(cnt,0,sizeof(cnt));
  for(int i = 0;i < N;i ++)
    G[i].clear();
}

int main()
{
  int n,m;
  while(cin >> n >> m)
  {
    init();
    for(int i = 0;i < n;i ++)
    {
      int id,val;
      cin >> id >> val;
      G[id].push_back(val);
      cnt[id] ++;
    }
    long long ans = 1e18 + 7;
    for(int i = 1;i <= m;i ++)
      sort(G[i].begin(),G[i].end());
    for(int lit = 1;lit <= n;lit ++)
    {
      long long sum = 0;
      memset(id,0,sizeof(id));
      int cur_cnt = cnt[1];
      vector<int> ret;
      for(int i = 2;i <= m;i ++)
      {
        int sz = G[i].size();
        int j = 0;
        for(;sz - j >= lit && j < sz;j ++)
          sum += G[i][j],cur_cnt ++;
        for(;j < G[i].size();j ++)
          ret.push_back(G[i][j]);
      }
      sort(ret.begin(),ret.end());
      for(int i = 0;i < ret.size() && cur_cnt < lit;i ++)
        sum += ret[i],cur_cnt ++;
      ans = min(ans,sum);
    }
    cout << ans << endl;
  }
}