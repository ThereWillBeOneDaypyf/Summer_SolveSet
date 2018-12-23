#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int m,k;
long long a[N],p[N],c[N],d[N];

long long judge(int vip)
{
  long long sum = 0;
  for(int i = 1;i <= k;i ++)
  {
    long long cur_d = d[i];
    cur_d = cur_d - cur_d * p[vip] / 100;
    sum += cur_d * c[i];
  }
  return max(sum,a[vip]);
}

int main()
{
  ios :: sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--)
  {
    cin >> m >> k; 
    for(int i = 1;i <= m;i ++)
      cin >> a[i] >> p[i];
    for(int i = 1;i <= k;i ++)
      cin >> c[i] >> d[i];
    a[0] = 0,p[0] = 0;
    long long ans = 1e18 + 7;
    for(int i = 0;i <= m;i ++)
    {
      ans = min(ans,judge(i));
    }
    cout << (ans + 9) / 10 << endl;
  }
}