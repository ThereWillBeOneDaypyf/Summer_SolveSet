#include<bits/stdc++.h>
using namespace std;

int a[10];
vector<int> v;

void dfs(int pos,int n,int cur)
{
  if(pos >= v.size())
    return;
  int ret = a[cur] - a[v[pos]];
  if(n >= ret)
  {
    v[pos] = cur;
    dfs(pos + 1,n - ret,cur);
  }
  else
  {
    if(cur + 1 == v[pos])
      return;
    dfs(pos,n,cur - 1);
  }
}

int main()
{
  int n;
  while(cin >> n)
  {
    int Min = 1e9;
    int pos = -1;
    for(int i = 1;i < 10;i ++)
    {
      cin >> a[i];
      if(a[i] <= Min)
      {
        Min = a[i];
        pos = i;
      }
    }
    v.clear();
    while(n >= a[pos])
    {
      n -= a[pos];
      v.push_back(pos);
    }
    if(v.empty())
    {
      cout << -1 << endl;
      continue;
    }
    dfs(0,n,9);
    for_each(v.begin(),v.end(),[](int a) { cout << a; });
    cout << endl;
  }
}