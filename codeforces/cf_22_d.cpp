#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int l,r;
  bool operator < (const Node& rhs) const
  {
    return r < rhs.r || (r == rhs.r && l < rhs.l);
  }
};

int main()
{
  int n;
  while(cin >> n)
  {
    vector<int> ans;
    vector<Node> v;
    for(int i = 0;i < n;i ++)
    {
      int l,r;
      cin >> l >> r;
      v.push_back({min(l,r),max(l,r)});
    }
    sort(v.begin(),v.end());
    ans.push_back(v[0].r);
    int cur = v[0].r;
    for(int i = 1;i < n;i ++)
    {
      if(cur >= v[i].l)
        continue;
      else 
      {
        ans.push_back(v[i].r);
        cur = v[i].r;
      }
    }
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i ++)
    {
      if(i)
        cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
}