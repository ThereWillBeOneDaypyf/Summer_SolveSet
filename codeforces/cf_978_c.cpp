#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

long long pre_sum[N];
long long a[N];

int main()
{
  int n,m;
  while(cin >> n >> m)
  {
    for(int i = 1;i <= n;i ++)
    {
      cin >> a[i];
      pre_sum[i] = pre_sum[i - 1] + a[i];
    }
    for(int i = 0;i < m;i ++)
    {
      long long p;
      cin >> p;
      int pos = lower_bound(pre_sum,pre_sum + n + 1,p) - pre_sum;
      cout << pos << " " << p - pre_sum[pos - 1] << endl;
    }
  }
}