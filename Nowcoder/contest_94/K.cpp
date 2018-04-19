#include<bits/stdc++.h>
using namespace std;

int x,y;
vector<pair<int,int> > v;
void dfs(int pos,int Max,int a,int b,map<long long,long long>& cnt)
{
  if(pos == Max)
  {
    cnt[1LL * a * y - 1LL * b * x] ++;
    return;
  }
  dfs(pos + 1,Max,a + v[pos].first,b + v[pos].second,cnt);
  dfs(pos + 1,Max,a,b,cnt);
}

int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n >> x >> y;
    v.clear();
    for(int i = 0;i < n;i ++)
    {
      int a,b;
      cin >> a >> b;
      v.push_back(make_pair(a,b));
    }
    map<long long,long long> cnt1;
    map<long long,long long> cnt2;
    dfs(0, n / 2,0,0,cnt1);
    dfs(n / 2,n,0,0,cnt2);
    long long ans = 0;
    for(auto temp : cnt1)
    {
      long long cur = temp.first;
      long long val = temp.second;
      ans += val * cnt2[-cur];
    }
    ans --;
    cout << ans << endl;
  }
}