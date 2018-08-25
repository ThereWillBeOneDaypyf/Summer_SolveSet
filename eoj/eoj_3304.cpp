#include<bits/stdc++.h>
using namespace std;

enum op
{
  EQ,
  G,
  GE,
  L,
  LE
};

int get_id(int val,vector<int>& v)
{
  return lower_bound(v.begin(),v.end(),val) - v.begin() + 1;
}

int solve(int val,vector<pair<op,int> >& v,vector<int>& tar)
{
  int ans = 0;
  for(auto temp : v)
  {
    int o = temp.first;
    int vv = get_id(temp.second,tar);
    if(o == EQ)
    {
      if(val == vv)
        ans ++;
    }
    else if(o == L)
    {
      if(val < vv)
        ans ++;
    }
    else if(o == LE)
    {
      if(val <= vv)
        ans ++;
    }
    else if(o == G)
    {
      if(val > vv)
        ans ++;
    }
    else 
    {
      if(val >= vv)
        ans ++;
    }
  }
  return ans;
}

int main()
{
  int n;
  while(cin >> n)
  {
    string s1,o;
    int x;
    vector<pair<op,int> > v;
    vector<int> tar;
    for(int i = 0;i < n;i ++)
    {
      cin >> s1 >> o >> x;
      if(o == "=")
        v.push_back(make_pair(EQ,x));
      else if(o == ">")
        v.push_back(make_pair(G,x));
      else if(o == "<")
        v.push_back(make_pair(L,x));
      else if(o == "<=")
        v.push_back(make_pair(LE,x));
      else v.push_back(make_pair(GE,x));
      tar.push_back(x);
      tar.push_back(x - 1);
      tar.push_back(x + 1);
    }
    sort(tar.begin(),tar.end());
    tar.erase(unique(tar.begin(),tar.end()),tar.end());
    int ans = 0;
    for(int i = 1;i <= tar.size();i ++)
      ans = max(ans,solve(i,v,tar)); 
    cout << ans << endl;
  }
}