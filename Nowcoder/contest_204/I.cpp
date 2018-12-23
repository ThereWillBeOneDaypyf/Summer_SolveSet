#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main()
{
  int n;
  while(cin >> n)
  {
    long long ans = 0;
    long long sum = 1;
    for(int i = 1;i <= n;i ++)
    {
      long long x;
      cin >> x;
      sum *= (x + 1);
      sum %= MOD;
      ans += (x + 1) * x / 2;
      ans %= MOD;
    }
    ans += sum;
    ans %= MOD;
    cout << ans << endl;
  }
}