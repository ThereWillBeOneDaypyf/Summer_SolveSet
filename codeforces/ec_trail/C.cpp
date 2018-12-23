#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

ull a[N];

void init()
{
  a[1] = 1,a[2] = 2;
  for(int i = 3;i < N;i ++)
  {
    a[i] = a[i - 1] + a[i - 2];
    a[i] %= MOD;
  }
}


int main()
{
  string n;
  init();
  while(cin >> n)
  {
    ull res = 0;
    for(auto ele : n)
    {
      res *= 10;
      res += ele - '0';
      res %= MOD;
    }
    for(int i = 1;i < N;i ++)
    {
      if(a[i] == res)
      {
        cout << i << endl;
        break;
      }
    }
  }
}