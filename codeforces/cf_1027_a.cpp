#include<bits/stdc++.h>
using namespace std;

vector<char> get_range(char x)
{
  int id = x - 'a';
  int offset1 = id + 1;
  int offset2 = id - 1;
  vector<char> v;
  if(offset1 < 26)
    v.emplace_back('a' + offset1);
  if(offset2 >= 0)
    v.emplace_back('a' + offset2);
  return v;
}


bool chk(char x,char y)
{
  vector<char> v1,v2;
  v1 = get_range(x);
  v2 = get_range(y);
  for(auto ele : v1)
    for(auto tar : v2)
      if(ele == tar)
        return true;
  return false;
}


bool judge(string& s)
{
  for(int i = 0;i < s.size() / 2;i ++)
  {
    if(!chk(s[i],s[(int)s.size() - 1 - i]))
      return false;
  }
  return true;
}


int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(judge(s))
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}