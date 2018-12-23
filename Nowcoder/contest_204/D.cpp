#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios :: sync_with_stdio(false);
  int n;
  while(cin >> n)
  {
    long long sum = 0;
    long long Min = 1e9 + 7;
    for(int i = 1;i <= n;i ++)
    {
      int x;
      cin >> x;
      sum += x;
      Min = min(1LL * x,Min);
    }
    sum += 1LL * (2 * (n - 1) - n) * Min;
    cout << sum << endl;
  }
}