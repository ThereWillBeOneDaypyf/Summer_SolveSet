#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int cnt[N];

int solve(string s,int n)
{
  int ans = 0;
  memset(cnt,0,sizeof(cnt));
  for(auto ele : s)
  {
    int id = tolower(ele) - 'a';
    if(isupper(ele))
      id += 26;
    cnt[id] ++;
  }
  int sz = s.size();
  for(int i = 0;i < 52;i ++)
  {
    if(cnt[i] == sz)
    {
      if(n == 1)
      {
        ans = sz - 1;
      }
      else ans = max(ans,cnt[i]); 
      continue;
    }
    int ret = sz - cnt[i];
    if(ret >= n)
    {
      ans = max(ans,cnt[i] + n);
    }
    else 
    {
      int ret_need = n - ret;
      ans = max(ans,sz);
    }
  }
  return ans;
}

int main()
{
  int n;
  while(cin >> n)
  {
    vector<pair<int,int> > v;
    for(int i = 0;i < 3;i ++) 
    {
      string s;
      cin >> s;
      int res = solve(s,n);
      v.push_back(make_pair(res,i));
    }
    sort(v.begin(),v.end());
    int Max = (*v.rbegin()).first;
    int flag = 1;
    for(int i = 0;i < 2;i ++)
    {
      if(Max == v[i].first)
      {
        flag = 0;
      }
    }
    int ans = (*v.rbegin()).second;
    if(!flag)
      cout << "Draw" << endl;
    else if(ans == 0)
      cout << "Kuro" << endl;
    else if(ans == 1)
      cout << "Shiro" << endl;
    else if(ans == 2)
      cout << "Katie" << endl;
    else if(ans == -1)
      cout << "Draw" << endl;
  }
}