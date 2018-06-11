#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int dp[N][11];

int n,m,k;
bool judge(int mid)
{
  long long ans = 0;
  for(int i = 1;i <= n;i ++)
  {
    ans += dp[mid][i];
    if(ans > m)
      return false;
  }
  return true;
}

int main()
{
  int T;
  scanf("%d",&T);
  int ka = 0;
  while(T--)
  {
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0;i < N;i ++)
    {
      for(int j = 1;j <= n;j ++)
      {
        dp[i][j] = m + 1;
      }
    }
    for(int i = 1;i <= n;i ++)
      dp[0][i] = 0;
    for(int i = 0;i < k;i ++)
    {
      int c,r,v;
      scanf("%d%d%d",&c,&r,&v);
      for(int j = N - 1;j >= v;j --)
      {
        dp[j][r] = min(dp[j][r],dp[j - v][r] + c);
      }
    }
    for(int i = 1;i <= n;i ++)
    {
      int cur = m + 1;
      for(int j = N - 1;j >= 0;j --)
      {
        dp[j][i] = min(dp[j][i],cur);
        cur = min(dp[j][i],cur);
      }
    }
    int l = 0,r = N - 1;
    int ans = 0;
    while(l <= r)
    {
      int mid = (l + r) / 2;
      if(judge(mid))
      {
        ans = mid;
        l = mid + 1;
      }
      else r = mid - 1;
    }
    printf("Case #%d:\n%d\n",++ka,ans);
  }
}