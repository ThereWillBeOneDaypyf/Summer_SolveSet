#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

bool vis[N];


int main()
{
  int n;
  while(cin >> n)
  {
    vector<int> v;
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      v.push_back(x);
    }
    memset(vis,0,sizeof(vis));
    vector<int> ans;
    for(auto it = v.rbegin();it != v.rend();it ++)
    {
      if(!vis[*it])
      {
        ans.push_back(*it);
        vis[*it] = 1;
      }
    }
    cout << ans.size() << endl;
    for(int i = ans.size() - 1;i >= 0;i --)
    {
      if(i != ans.size() - 1)
        cout << " ";
      cout << ans[i];
    }
    cout << endl;

  }
}