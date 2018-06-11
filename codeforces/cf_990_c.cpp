#include<bits/stdc++.h>
using namespace std;

map<int,int> cnt;

void solve(string& s)
{
  stack<char> st;
  int all = 0;
  for(auto ele : s)
  {
    if(ele == '(')
    {
      st.push('(');
    }
    else 
    {
      if(st.empty())
        all--;
      else st.pop();
    }
  }
  if(all != 0 && !st.empty())
    return;
  else if(all)
    cnt[all] ++;
  else cnt[st.size()] ++;
}

int main()
{
  int n;
  while(cin >> n)
  {
    string s;
    cnt.clear();
    for(int i = 0;i < n;i ++)
    {
      cin >> s;
      solve(s);
    }
    long long ans = cnt[0];
    ans += 1LL * cnt[0] * (cnt[0] - 1);
    for(auto temp : cnt)
    {
      if(temp.first > 0)
      {
        ans += 1LL * temp.second * (cnt[-temp.first]);
      }
    }
    cout << ans << endl;
  }
}