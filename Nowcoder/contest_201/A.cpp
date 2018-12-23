#include<bits/stdc++.h>
using namespace std;


int main()
{
  int a,b,c,d,e,f;
  while(cin >> a >> b >> c >> d >> e >> f)
  {
    int ans = 0;
    ans += min(a,e);
    ans += min(b,f);
    ans += min(c,d);
    cout << ans << endl;
  }
}