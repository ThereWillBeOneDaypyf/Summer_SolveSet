#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int MOD = 1e9;

long long a[N];
long long pre_sum[N][31];

int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n ;i ++)
      scanf("%lld",a + i);
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= 30;i ++)
    {
      for(int j = 1;j <= n;j ++)
      {
        pre_sum[j][i] = pre_sum[j - 1][i] + a[j] / i;
      }
    }
    long long MAX = *max_element(a + 1,a + n + 1);
    long long ans = 0;
    for(int i = 0;i < m;i ++)
    {
      long long p;
      scanf("%lld",&p);     
      long long cur_tar = p;
      int cur_pos = 0;
      long long temp_ans = 0;
      for(int j = 1;j <= 30;j ++)
      {
        auto temp_pos = upper_bound(a + cur_pos + 1,a + n + 1,cur_tar) - a;
        if(temp_pos != cur_pos)
        {
          temp_ans += pre_sum[temp_pos - 1][j] - pre_sum[cur_pos][j];
          // cout << " + " << pre_sum[temp_pos - 1][i] - pre_sum[cur_]
          cur_pos = temp_pos - 1;
        }
        temp_ans %= MOD;
        if(MAX / p >= cur_tar)
          cur_tar *= p;
        else 
        {
          temp_ans += pre_sum[n][j + 1] - pre_sum[cur_pos][j + 1];
          temp_ans %= MOD;
          break;
        }
      }
      ans += 1LL * (i + 1) * (temp_ans);
      ans %= MOD;
    }
    printf("%lld\n",ans);
  }
}
