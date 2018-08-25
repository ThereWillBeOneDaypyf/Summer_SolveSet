#include<iostream>
#include<cmath>
#include<cstdio>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;

long long ans = 1e18;
int ans_sz = 100;

long long Abs(long long x)
{
  if(x < 0)
    return -x;
  return x;
}

void dfs(int pos,long long sum,int t,const vector<long long>& v,vector<long long>& s,map<long long,int>& sz)
{
  if(pos >= v.size())
  {
    if(!t)
      return;
    if(!sz.count(sum))
    {
      s.push_back(sum);
      sz[sum] = t; 
    }
    else sz[sum] = min(sz[sum],t);
    if(Abs(sum) < ans || (Abs(sum) == ans && sz[sum] < ans_sz))    
    {
      ans = Abs(sum);
      ans_sz = sz[sum];
    }
    return;
  }
  dfs(pos + 1,sum,t,v,s,sz);
  dfs(pos + 1,sum + v[pos],t + 1,v,s,sz);
}

void solve(long long cur_ans,int cur_sz)
{
  if(Abs(cur_ans) < ans || (Abs(cur_ans) == ans && cur_sz < ans_sz))
    ans = Abs(cur_ans),ans_sz = cur_sz;
}

int main()
{
  int n;
  while(scanf("%d",&n) == 1)
  // while(cin >> n)
  {
    if(!n)
      break;
    ans = 1e18;
    ans_sz = 0;
    vector<long long> v1,v2;
    for(int i = 0;i < n;i ++)
    {
      long long x;
      scanf("%lld",&x);
      // cin >> x;
      if(i < n / 2)
        v1.push_back(x);
      else v2.push_back(x);
    }
    vector<long long> s1,s2;
    map<long long,int> sz1,sz2;
    dfs(0,0LL,0,v1,s1,sz1);
    dfs(0,0LL,0,v2,s2,sz2);
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    for(int i = 0;i < s1.size();i ++)
    {
      vector<long long> :: iterator it = lower_bound(s2.begin(),s2.end(),-s1[i]);
      if(it != s2.end())
        solve(*it + s1[i],sz1[s1[i]] + sz2[*it]);
      if(it != s2.begin())
      {
        it --;
        solve(*it + s1[i],sz1[s1[i]] + sz2[*it]);
      }
    }
    printf("%lld %d\n",ans,ans_sz);
    // cout << ans << " " << ans_sz << endl;
  }
}
