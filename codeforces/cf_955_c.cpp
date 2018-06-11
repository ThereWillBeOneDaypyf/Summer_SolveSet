#include<bits/stdc++.h>
using namespace std;

vector<long long> v;
const long long Max = 1e18;

void init()
{
  for(long long i = 2;i <= 1e6;i ++)
  {
    long long cur = i;
    long long base = i * i;
    for(int j = 3;cur <= Max / base;j += 2)
    {
      cur *= base;
      if((long long)sqrt(cur) * (long long)sqrt(cur) == cur)
        continue;
      v.push_back(cur);
    }
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
}
int main()
{
  int q;
  init();
  while(cin >> q)
  {
    for(int i = 0;i < q;i ++)
    {
      long long l,r;
      cin >> l >> r;
      long long cnt = upper_bound(v.begin(),v.end(),r) - lower_bound(v.begin(),v.end(),l);
      cnt += (long long)sqrt(r)  - (long long)sqrt(l - 1);
      cout << cnt << endl;
    }
  }
}