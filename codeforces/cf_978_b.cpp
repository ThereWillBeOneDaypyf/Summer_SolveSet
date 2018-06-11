#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string s;
  while(cin >> n >> s)
  {
    int cnt = 0;
    int ans = 0;
    for(int i = 0;i < n;i ++)
    {
      if(s[i] == 'x')
      {
        cnt ++;
        if(cnt >= 3)
        {
          ans ++;
        }
      }
      else cnt = 0;
    }
    cout << ans << endl;
  }
}