#include<bits/stdc++.h>
using namespace std;

int judge(int n)
{
  int cnt = 0;
  for(int i = 1;i <= n;i ++)
  {
    for(int j = 1;j <= n;j ++)
    {
      double temp1 = 1.0 * i * log(j);
      double temp2 = 1.0 * j * log(i);
      if(temp1 == temp2)
        cnt ++;
    }
  }
  return cnt;
}

int main()
{
  long long n;
  while(cin >> n)
  {
    long long ans = n;
    if(n >= 4)
      ans += 2;
    cout << ans << endl;
    // cout << ans << " " << judge(n) << endl;
  }
}