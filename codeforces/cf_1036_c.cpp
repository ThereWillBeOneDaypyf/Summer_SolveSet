#include<bits/stdc++.h>
using namespace std;

long long dp[20][10][20];
int a[20];

long long dfs(int pos,int pre,int cnt,bool limit)
{
  if(pos == -1 && cnt <= 3)
    return 1;
  else if(pos == -1)
    return 0;
  if(!limit && dp[pos][pre][cnt] != -1)
    return dp[pos][pre][cnt];
  int up = limit ? a[pos] : 9;
  long long ans = 0;
  for(int i = 0; i<= up;i ++)
  {
    int temp_pre = i,temp_cnt = cnt;
    if(i != 0)
      temp_cnt ++;
    ans += dfs(pos - 1,temp_pre,temp_cnt,limit && i == a[pos]);
  }
  if(!limit)
    dp[pos][pre][cnt] = ans;
  return ans;
}

void init()
{
  memset(dp,-1,sizeof(dp));
}

long long solve(long long n)
{
  int cnt = 0;
  memset(a,0,sizeof(a));
  while(n)
  {
    a[cnt ++] = n % 10;
    n /= 10;
  }
  return dfs(cnt - 1,0,0,1);
}


int main()
{
  int T;
  while(cin >> T)
  {
    init();
    for(int i = 0;i < T;i ++)
    {
      long long l,r;
      cin >> l >> r;
      cout << solve(r) - solve(l - 1) << endl;
    }
  }
}