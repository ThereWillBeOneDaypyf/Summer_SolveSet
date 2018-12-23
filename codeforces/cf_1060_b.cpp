#include<bits/stdc++.h>
using namespace std;

void dfs(string& s,int pos,string& res,bool flag)
{
  if(pos == 0)
  {
    if(flag)
    {
      res.push_back(s[pos]);
    }
    return;
  }
  if(s[pos] == '9')
  {
    res.push_back('9');
    dfs(s,pos - 1,res,1 & flag);
  }
  else 
  {
    res.push_back('9');
    dfs(s,pos - 1,res,0);
  }
}

int cal(string& s)
{
  int sum = 0;
  for(auto ele : s)
    sum += ele - '0';
  return sum;
}

int main()
{
  string s;
  while(cin >> s)
  {
    long long res = atoll(s.c_str());
    string half = "";
    dfs(s,s.size() - 1,half,1);
    long long half_val =atoll(half.c_str());
    long long temp = res - half_val;
    string temp_str = to_string(temp);
    // cout << half << " " << temp_str << endl;
    cout << cal(half) + cal(temp_str) << endl;
  }
}