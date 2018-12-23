#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N],b[N];
int n,m;

long long judge(int tar)
{
  long long ans = 0;
  for(int i = 0;i < n;i ++)
  {
    if(a[i] < tar)
      ans += tar - a[i];
  }
  for(int i = 0;i < m;i ++)
    if(b[i] > tar)
      ans += b[i] - tar;
  return ans;
}

int main()
{
  while(cin >> n >> m)
  {
    for(int i = 0;i < n;i ++)
      cin >> a[i];
    for(int i = 0;i < m;i ++)
      cin >> b[i];
    int l = 0, r = 1e9 + 7;
    long long ans = 1e18;
    while(l <= r)
    {
      int mid = (l + r) / 2;
      int mmid = (mid + r) / 2;
      long long res_mid = judge(mid);
      long long res_mmid = judge(mmid);
      ans = min(ans,res_mid);
      ans = min(ans,res_mmid);
      if(res_mid <= res_mmid)
        r = mmid - 1;
      else l = mid + 1;
    }
    cout << ans << endl;
  }
}