#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,m,tar;
  while(cin >> n >> m >> tar)
  {
    int ret = 1;
    vector<int> v[2];
    int flag = 0;
    for(int i = 1;i <= n;i ++)
    {
      if(!ret)
      {
        flag = 1;
      }
      if(i == tar)
        continue;
      if(ret)
        ret --;
      v[flag].push_back(i);
    }
    if(m < n - 1 || m > ((n - 2) * (n - 3) / 2 + (n - 1)))
    {
      cout << -1 << endl;
      continue;
    }
    for(int i = 0;i < 2;i ++)
    {
      for(auto u : v[i])
      {
        m --;
        cout << tar << " " << u << endl;
        // ans.push_back(make_pair(tar,u));
      }
    }
    for(int k = 0;k < 2;k ++)
    {
      for(int i = 0;i < v[k].size();i ++)
      {
        for(int j = i + 1;j < v[k].size();j ++)
        {
          if(!m)
            break;
            // ans.push_back(make_pair(v[k][i],v[k][j]));
            cout << v[k][i] << " " << v[k][j] << endl;
            m --;
        }
      }
    }
  }
}