#include<bits/stdc++.h>
using namespace std;

int main()
{
  int hh,mm;
  long long h,d,c,n;
  while(cin >> hh >> mm >> h >> d >> c >> n)  
  {
    long long cur = ((long long)(h + n - 1) / n) * c;
    if(hh >= 20)
    {
      printf("%.6lf\n",1.0 * cur * 0.8);
      continue;
    }
    else 
    {
      int ret_min = 60 - mm;
      ret_min += 60 * (19 - hh);
      double ans = ((long long)(h + ret_min * d + n - 1) / n) * c;
      ans *= 0.8;
      ans = min(ans,(double)cur);
      printf("%.6lf\n",ans);
    }
  }
}