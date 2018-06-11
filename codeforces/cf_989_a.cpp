#include<bits/stdc++.h>
using namespace std;

string s;

bool judge(int pos)
{
  set<char> cnt;
  for(int i = pos;i < pos + 3;i ++)
  {
    if(s[i] == '.')
      return false;
    cnt.insert(s[i]);
  }
  return (3 == cnt.size());
}

int main()
{
  while(cin >> s)
  {
    int flag = 0;
    for(int i = 0;i <= (int)s.size() - 3;i ++)
    {
      if(judge(i))
        flag = 1;
    }
    if(flag)
      cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}