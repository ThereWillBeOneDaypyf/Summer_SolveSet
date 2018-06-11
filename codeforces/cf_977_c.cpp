#include<bits/stdc++.h>
using namespace std;


int main()
{
  int n,k;
  while(cin >> n >> k)
  {
    vector<int> v;
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(),v.end());
    if(k == 0)
    {
      if(*v.begin() == 1)
      {
        cout << -1 << endl;
      }
      else cout << *v.begin() - 1 << endl;
    }
    else 
    {
      int tar = v[k - 1];
      int cnt = 0;
      for(int i = k - 1;i < v.size();i ++)
      {
        if(v[i] == tar)
          cnt ++;
      }
      if(cnt > 1)
        cout << - 1 << endl;
      else cout << tar << endl;
    }
  }
}