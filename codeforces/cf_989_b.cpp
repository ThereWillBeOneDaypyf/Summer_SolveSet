#include<bits/stdc++.h>
using namespace std;
string s;
int n,p;

void solve(string& s)
{
  for(auto& ele : s)
    if(ele == '.')
      ele = '0';
}

bool judge(string& s)
{
  for(int i = 0;i < n - p;i ++)
  {
    if(s[i] != s[i + p])
    {
      if(s[i] == '.')
      {
        s[i] = (s[i + p] == '0') ? '1' : '0';
      }
      else
      {
        s[i + p] = (s[i] == '0') ? '1' : '0';
      }
      solve(s);
      return true;
    }
    else if(s[i] == '.' && s[i + p] == '.')
    {
      s[i] = '0',s[i + p] = '1';
      solve(s);
      return true;
    }
  } 
  return false;
}

int main()
{
  while(cin >> n >> p)
  {
    cin >> s;
    if(judge(s))
      cout << s << endl;
    else cout << "No" << endl;
  }
}