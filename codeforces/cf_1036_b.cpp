#include<bits/stdc++.h>
using namespace std;

void solve1(long long x,long long y,long long k,long long& ans)
{
  long long a = k - abs(x - y);
  if(x >= a && y <= a)
    ans = max(ans,a);
  if(x <= a && y >= a)
    ans = max(ans,a);
}

void solve2(long long x,long long y,long long k,long long& ans)
{
  long long a = k + x + y;
  if(a % 3 == 0 && x < a && y < a)
    ans = max(ans,a);
}

void solve3(long long x,long long y,long long k,long long& ans)
{
  long long a = x + y - k;
  if(x > a && y > a)
    ans = max(ans,a);
}

int main()
{
  int q;
  while(cin >> q)
  {
    for(int i = 0;i < q;i ++)
    {
      long long x,y,k;
      cin >> x >> y >> k;
      long long use = abs(x - y);
      long long ans = -1;
      if(max(x,y) > k)
        cout << - 1 << endl;
      else 
      {
        if((x + y) % 2)
          cout << k - 1 << endl;
        else 
        {
          if((k - max(x,y)) % 2)
            cout << k - 2 << endl;
          else cout << k << endl;
        }
      }
    }
  }
}