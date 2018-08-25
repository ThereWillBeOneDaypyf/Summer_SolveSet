#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int a[N];

int main()
{
  int n, m, x;
  while (~scanf("%d%d%d", &n, &m, &x))
  {
    long long ans = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &a[i]);
      if (i <= m)
      {
        sum += a[i];
      }
      else
      {
        sum += a[i];
        sum -= a[i - m];
      }
      if (sum > x)
      {
        ans += sum - x;
        a[i] -= (sum - x);
        sum = x;
      }
    }
    printf("%lld\n", ans);
  }
}