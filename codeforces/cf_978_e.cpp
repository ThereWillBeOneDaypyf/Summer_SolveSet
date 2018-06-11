#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

long long a[N];

int main()
{
  long long n,m;
  while(cin >> n >> m)
  {
    a[0] = 0;
    for(int i = 1;i <= n;i ++)
    {
      cin >> a[i];
    }
    long long sum = 0;
    long long atleast = 0;
    long long ans = m;
    for(int i = 1;i <= n;i ++)
    {
      sum += a[i];
      long long cur = m - sum;
      atleast = max(atleast,-sum);
      ans = min(ans,cur);
    }
    long long res = ans - atleast + 1;
    if(res < 0)
      cout << 0 << endl;
    else 
      cout << res << endl;
  }
}