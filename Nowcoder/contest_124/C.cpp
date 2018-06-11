#include<bits/stdc++.h>
using namespace std;

const int N = 66;

int a[N];
long long p[N];

void init()
{
  p[0] = 1;
  for(int i = 1;i < 64;i ++)
    p[i] = p[i - 1] * 2;
}

void to2(long long n)
{
  for(int i = 0;i < 64;i ++)
  {
    a[i] = ((n & p[i]) != 0);
    // cout << a[i];
  }
  // cout << endl;
}

long long to10()
{
  long long base = 1;
  long long ans = 0;
  for(int i = 0;i < 64;i ++)
  {
    ans += base * a[i];
    base *= 2;
  }
  return ans;
}


int main()
{
  long long n;
  init();
  while(cin >> n)
  {
    if(n < 0)
    {
      n = - n;
      to2(n);
      for(int i = 0;i < 64;i ++) 
      {
        a[i] = 1 - a[i];
      }
      long long cur = to10();
      cur ++;
      to2(cur);
    }
    else to2(n);
    int cnt = 0;
    for(int i = 0;i < 64;i ++)
      cnt += a[i];
    cout << cnt << endl;
  }
}
