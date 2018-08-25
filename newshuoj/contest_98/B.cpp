#include<bits/stdc++.h>
using namespace std;

string solve(int n)
{
  string s;
  if(n < 10)
  {
    s += '0';
    s += '0' + n;
  }
  else 
  {
    s += n / 10 + '0';
    s += n % 10 + '0';
  }
  return s;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    string s;
    cin >> s;
    string ans;
    for(int i = 0;i < s.size();i ++)
    {
      ans += solve(s[i] - 'a' + 1);
    }
    cout << ans << endl;
  }
}