#include<bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    string s;
    cin >> s;
    int ret = 0;
    for(auto x : s)
    {
      x -= '0';
      ret *= 10;
      ret += x;
      ret %= 11;
    }
    if(!ret)
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}