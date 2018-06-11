#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long k,n,s,p;
  while(cin >> k >> n >> s >> p)
  {
    long long ans = ceil(1.0 * ceil(1.0 * n / s) * k / p);
    cout << ans << endl;
  }
}