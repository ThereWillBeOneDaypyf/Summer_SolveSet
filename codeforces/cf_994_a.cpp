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
      int x;
      cin >> x;
      v.push_back(x);
    }
    set<int> s;
    for(int i = 0;i < m;i ++)
    {
      int x;
      cin >> x;
      s.insert(x);
    }
    for(auto ele : v)
    {
      if(s.count(ele))
        cout << ele << " ";
    }
    cout << endl;
  }
}