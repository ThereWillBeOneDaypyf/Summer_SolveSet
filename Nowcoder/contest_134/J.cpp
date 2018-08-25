#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  while(cin >> n)
  {
    map<int,int> cnt;
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      cnt[x] ++;
    }
    int ans = 0;
    for(auto temp : cnt)
      ans += temp.second - 1;
    cout << ans << endl;
  }
}