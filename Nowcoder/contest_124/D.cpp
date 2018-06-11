#include<bits/stdc++.h>
using namespace std;

long long solve(long long n)
{
  long long l = 1,r = sqrt(1e15 + 1);
  long long ans = -1;
  while(l <= r)
  {
    long long mid = (l + r) / 2;
    if(mid * mid <= n)
    {
      ans = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }
  return n - ans;
}

int main()
{
  long long n;
  while(cin >> n)
    cout << solve(n) << endl;
}