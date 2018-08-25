#include<bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0 ;i < n;i ++)
    {
      int x;
      cin >> x;
      a.push_back(x);
    }
    sort(a.begin(),a.end(),greater<int>());
    int ans = 0;
    vector<int> v;
    for(int i = 0;i < n;i ++)
    {
      if(v.empty())
      {
        v.push_back(a[i]);
      }
      else 
      {
        int flag = 0;
        for(auto& ele : v)
        {
          if(ele + a[i] <= 4)
          {
            ele += a[i];
            flag = 1;
            break;
          }
        }
        if(!flag)
          v.push_back(a[i]);
      }
      sort(v.begin(),v.end(),greater<int>());
    }
    cout << v.size() << endl;
  }
}