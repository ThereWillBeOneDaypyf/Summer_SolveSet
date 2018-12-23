#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  int n;
  while(cin >> n >> s)
  {
    int cnt = 0;
    int x = 0;
    for(int i = 0;i < s.size();i ++)
    {
      if(s[i] == '8')
        cnt ++;
      else x ++;
    }
    int ans = 0;
    for(int i = 0;i <= cnt;i ++)
    {
      ans = max(ans,min(i,(n - i)/10));
    }
    cout << ans << endl;
  }
}