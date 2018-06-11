#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  while(cin >> s)
  {
    int cnt = 0;
    for(int i = 0;i < s.size();i ++)
    {
      char temp = s[i];
      if(temp == '-')
        cnt ++;
    }
    int ret = (int)s.size() - cnt;
    if(ret == 0)
    {
      cout << "YES" << endl;
      continue;
    }
    if(cnt % ret == 0)
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}