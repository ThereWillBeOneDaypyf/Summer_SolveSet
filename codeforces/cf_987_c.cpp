#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 7;

int Min[N][N];
vector<int> tar;

void init()
{
  for (int i = 0; i < N; i++)
    for(int j = 0;j < N;j ++)
      Min[i][j] = 1e9 + 7;
  tar.clear();
}

int get_id(int val)
{
  return lower_bound(tar.begin(), tar.end(), val) - tar.begin();
}

int main()
{
  int n;
  while (cin >> n)
  {
    init();
    vector<int> v;
    vector<int> c;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      v.push_back(x);
      tar.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      c.push_back(x);
    }
    sort(tar.begin(), tar.end());
    tar.erase(unique(tar.begin(), tar.end()), tar.end());
    int ans = 1e9 + 7;
    for(int i = 0;i < n;i ++)
    {
      int id = get_id(v[i]);
      for(int j = 0;j < i;j ++)
        Min[j][id] = min(Min[j][id],c[i]);
    }
    for(int i = 0;i < n;i ++)
    {
      for(int j = n - 1;j >= 0;j--) 
      {
        Min[i][j] = min(Min[i][j],Min[i][j + 1]);
      }
    }
    for(int i = 0;i < n;i ++)
    {
      for(int j = i + 1;j < n;j ++)
      {
        if(v[i] < v[j])
        {
          int id = get_id(v[j]);
          ans = min(ans,c[i] + c[j] + Min[j][id + 1]);
          // cout << i << " " << j << endl;
          // cout << c[i] << " " << c[j] << " " << Min[j + 1][id + 1] << endl;
        }
      }
    }
    if (ans >= 1e9 + 7)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}