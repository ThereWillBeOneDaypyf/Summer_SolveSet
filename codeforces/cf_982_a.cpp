#include<bits/stdc++.h>
using namespace std;

string s;

bool judge(int pos)
{
  int flag = 0;
  if(pos != 0)
    flag |= (s[pos - 1] == '1');  
  if(pos != s.size() - 1)
    flag |= (s[pos + 1] == '1');
  return flag;
}
bool check(int pos)
{
  int flag = 0;
  if(pos != 0)
    flag |= (s[pos - 1] == '1');
  if(pos != s.size() - 1)
    flag |= (s[pos + 1] == '1');
  return (flag);
}
int main()
{
  int n;
  while(cin >> n >> s)
  {
    int flag = 1;
    for(int i = 0;i < s.size();i ++)
    {
      if(s[i] == '1')
      {
        if(check(i))
          flag = 0;
      }
      else if(!judge(i))
      {
        flag = 0;
        break;
      }
    }
    if(flag)
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
