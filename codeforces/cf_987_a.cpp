#include<bits/stdc++.h>
using namespace std;
map<string,int> t;
map<int,string> ans;

int main()
{
  t["purple"] = 0;
  t["green"] = 1;
  t["blue"] = 2;
  t["orange"] = 3;
  t["red"] = 4;
  t["yellow"] = 5;
  ans[0] = "Power";
  ans[1] = "Time";
  ans[2] = "Space";
  ans[3] = "Soul";
  ans[4] = "Reality";
  ans[5] = "Mind";
  int vis[6];
  int n;
  while(cin >> n)
  {
    memset(vis,0,sizeof(vis));
    for(int i = 0;i < n;i ++)
    {
      string s;
      cin >> s;
      vis[t[s]] = 1;
    }
    vector<int> v;
    for(int i = 0;i < 6;i ++)
    {
      if(!vis[i])
        v.push_back(i);
    }
    cout << v.size() << endl;
    for(auto ele : v)
      cout << ans[ele] << endl;
  }
}