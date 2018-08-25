#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,h,a,b,k;
  while(cin >> n >> h >> a >> b >> k)
  {
    for(int i = 0;i < k;i ++) 
    {
      int ta,fa,tb,fb;
      cin >> ta >> fa >> tb >> fb;
      if(ta == tb)
      {
        cout << abs(fa - fb) << endl;
      }
      else
      {
        int ans = 2e9 + 7;
        if(fa >= a && fa <= b)
        {
          ans = min(ans,abs(ta - tb) + abs(fa - fb));
        }
        if(fb >= a && fb <= b)
        {
          ans = min(ans,abs(ta - tb) + abs(fa - fb));
        }
        ans = min(ans,abs(ta - tb) + abs(fa - a) + abs(fb - a));
        ans = min(ans,abs(ta - tb) + abs(fa - b) + abs(fb - b));
        cout << ans << endl;
      }
    }
  }
}