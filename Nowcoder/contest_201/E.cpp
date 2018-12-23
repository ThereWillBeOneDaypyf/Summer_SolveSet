#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  while(cin >> n >> m)
  {
    vector<int> v;
    for(int i = 0;i < n;i ++)
    {
      int d;
      cin >> d;
      v.push_back(d);
    }
    sort(v.begin(),v.end());
    int cur = v[0];
    int ans = 1;
    for(int i = 1;i < n;i ++)
    {
      if(v[i] - cur > m)
      {
        ans ++;
      }
      cur = v[i];
    }
    cout << ans << endl;
  }
}