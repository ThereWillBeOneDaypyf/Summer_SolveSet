#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;

long long a[N];
long long f[N];
long long pre_w[N];
long long suf_w[N];
long long pre_sum[N];

int main()
{
  long long n;
  while(cin >> n)
  {
    memset(a,0,sizeof(a));
    memset(pre_w,0,sizeof(pre_w));
    memset(suf_w,0,sizeof(suf_w));
    memset(pre_sum,0,sizeof(pre_sum));
    for(long long i = 1;i <= n;i ++ )
    {
      cin >> a[i];
      a[i] %= MOD;
      pre_w[i] = pre_w[i - 1] + 1LL * i * a[i];
      pre_sum[i] = pre_sum[i - 1] + a[i];
      pre_w[i] %= MOD;
      pre_sum[i] %= MOD;
    }
    for(long long i = 1;i <= n;i ++)
      cin >> f[i];
    for(long long i = n;i >= 1;i --)
    {
      suf_w[i] = suf_w[i + 1] + 1LL * (n - i + 1) * a[i];
      suf_w[i] %= MOD;
    }
    long long ans = 0;
    for(long long i = 1;i <= n;i ++)
    {
      long long ret = min(n - i,i - 1);
      long long res = 0;
      res += suf_w[n - ret + 1]; 
      res %= MOD;
      res += pre_w[ret];
      res %= MOD;
      res += 1LL * (ret + 1) * (pre_sum[n - ret] - pre_sum[ret]);
      res %= MOD;
      res *= f[i];
      res %= MOD;
      ans += res;
      ans %= MOD;
    }
    cout << ans << endl;
  }
}