#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int n;
  while(cin >> n >> s)
  {
    map<string,int> cnt;
    for(int i = 0;i < s.size() - 1;i ++)
    {
      string temp(s.begin() + i,s.begin() + i + 2);
      cnt[temp] ++;
    }
    string ans;
    int Max = 0;
    for(auto temp : cnt)
    {
      if(temp.second >= Max)
      {
        Max = temp.second;
        ans = temp.first;
      }
    }
    cout << ans << endl;
  }
}