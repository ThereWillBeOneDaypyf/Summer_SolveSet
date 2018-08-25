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
    vector<int> v(n,0);
    for(int i = 0;i < n;i ++)
      cin >> v[i];
    sort(v.begin(),v.end());
    int sum = accumulate(v.begin(),v.end(),0);
    int cur = 0;
    int cnt = 0;
    for(auto it = v.rbegin();it != v.rend();it ++)
    {
      cur += *it;
      cnt ++;
      if(cur >sum / 2)
        break;
    }
    cout << cnt << endl;
  }
}