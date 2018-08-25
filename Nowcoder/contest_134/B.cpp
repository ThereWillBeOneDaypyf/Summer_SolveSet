#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  while(cin >> n)
  {
    vector<char> v;
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      v.push_back(x + '0');
    }
    vector<long long> res;
    for(int i = 0;i < n;i ++)
    {
      for(int j = i + 1;j <= i + 9;j ++)
      {
        string s(v.begin() + i,v.begin() + j);
        res.push_back(stoll(s));
      }
    }
    sort(res.begin(),res.end());
    long long ans = -1;
    for(long long i = 0;;i ++)
    {
      auto pos = lower_bound(res.begin(),res.end(),i);
      if(pos == res.end() || *pos != i)
      {
        cout << i << endl;
        break;
      }
    }
  }
}