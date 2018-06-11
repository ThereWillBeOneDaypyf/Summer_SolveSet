#include<bits/stdc++.h>
using namespace std;


int main()
{
  int n;
  while(scanf("%d",&n) == 1)
  {
    for(int i = 0;i < n;i ++)
    {
      long long p,q,b;
      scanf("%lld%lld%lld",&p,&q,&b);
      if(p == 0)
      {
        printf("Finite\n");
        continue;
      }
      else
      {
        long long g = __gcd(p,q);
        p /= g;
        q /= g;
        while(__gcd(b,q) != 0)
        {
          long long cur = __gcd(b,q);
          if(cur == 1)
            break;
          while(q % cur == 0)
            q /= cur;
        }
        if(q == 1)
          printf("Finite\n");
        else
          printf("Infinite\n");
      }
    }
  }
}