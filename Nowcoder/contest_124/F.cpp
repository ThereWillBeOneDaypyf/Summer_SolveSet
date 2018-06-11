#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int speed;
  int val;
  bool operator <(const Node& rhs) const
  {
    return val > rhs.val;
  }

};

int main()
{
  int n;
  int T;
  cin >> T;
  while(T--)
  {
    cin >> n;
    vector<Node> v;
    for(int i = 0;i < n;i ++)
    {
      int s;
      cin >> s;
      v.push_back({s,0});
    }
    for(int i = 0;i < n;i ++)
    {
      int val;
      cin >> val;
      v[i].val = val;
    }
    multiset<int> tar;
    for(int i = 0;i < n;i ++)
    {
      int s;
      cin >> s;
      tar.insert(s);
    }
    sort(v.begin(),v.end());
    long long ans = 0;
    for(int i = 0;i < v.size();i ++)
    {
      auto pos = tar.upper_bound(v[i].speed);
      if(pos == tar.end())
        ans -= v[i].val; 
      else
      {
        ans += v[i].val;
        tar.erase(pos);
      }
    }
    cout << ans << endl;
  }
}