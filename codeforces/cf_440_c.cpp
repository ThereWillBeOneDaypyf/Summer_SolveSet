#include<bits/stdc++.h>
using namespace std;
const int N = 20;

long long x[N];

int dfs(long long val,int d)
{
  if(d <= 0)
    return 0;
  int cnt = val / x[d];
  return cnt * d + min(dfs(x[d] - val % x[d],d - 1) + d,dfs(val % x[d], d - 1));
}

int main()
{
  long long n;
  for(int i = 1;i <= 16;i ++)
    x[i] = x[i - 1] * 10 + 1;
  while(cin >> n)
  {
    cout << dfs(n,16) << endl;
  }
}