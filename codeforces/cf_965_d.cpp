#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,l;
  while(cin >> n >> l)
  {
    vector<int> a;
    for(int i = 1;i < n;i ++)
    {
      int x;
      cin >> x;
      a.push_back(x);
    }
    long long sum = 0;
    for(int i =0 ;i < l;i++)
    {
      sum += a[i];
    }
    long long ans = sum;
    for(int i = l;i < n - 1;i ++)
    {
      sum += a[i];
      sum -= a[i - l];
      ans = min(ans,sum);
    }
    cout << ans << endl;
  }
}