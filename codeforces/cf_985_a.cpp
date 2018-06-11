#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;

int a[N];

int main()
{
  int n;
  while(cin >> n)
  {
    for(int i = 1;i <= n / 2;i ++)
      cin >> a[i];
    sort(a + 1,a + n / 2 + 1);
    int ans = 0;
    for(int i = 1;i <= n;i += 2)
    {
      int cur = a[(i + 1) / 2];
      ans += abs(cur - i);
    }
    int sum = 0;
    for(int i = 2;i <= n;i += 2)
    {
      int cur = a[i / 2];
      sum += abs(cur - i);
    }
    cout << min(ans,sum) << endl;
  }
}