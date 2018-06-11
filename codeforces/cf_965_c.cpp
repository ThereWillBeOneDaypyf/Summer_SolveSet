#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long n,k,m,d;
  while(cin >> n >> k >> m >> d)
  {
    long long ans = 0;
    for(long long i = 1;i <= d;i ++)
    {
      long long Max_x = n / ((i - 1) * k + 1);
      if(Max_x <= 0)
        break;
      Max_x = min(Max_x,m);
      ans = max(ans,Max_x * i);
    }
    cout << ans << endl;
  }
}