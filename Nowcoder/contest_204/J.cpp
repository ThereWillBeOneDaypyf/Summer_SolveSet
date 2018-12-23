#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios :: sync_with_stdio(false);
  int n,m;
  while(cin >> n >> m)
  {
    vector<pair<int,string> > v;
    set<string> tar;
    for(int i = 0;i < m;i ++)
    {
      int x;
      string s;
      cin >> x >> s;
      v.push_back(make_pair(x,s));
      tar.insert(s);
    }
    set<int> ans;
    for(int i = 1;i <= n;i ++)
      ans.insert(i);
    set<int> first;
    for(auto s : tar)
    {
      bool flag = 0;
      for(auto temp : v)
      {
        if(temp.second == s) 
        {
          if(!flag)
          {
            flag = 1;
            first.insert(temp.first);
          }
          else
            ans.insert(temp.first);
        }
      }
    }
    for(auto fi : first)
    {
      auto it = ans.find(fi);
      if(it != ans.end())
        ans.erase(it);
    }
    bool ok = 0;
    for(auto ele : ans)
    {
      if(ok)
        cout << " ";
      cout << ele;
      ok = 1;
    }
    cout << endl;
  }
}