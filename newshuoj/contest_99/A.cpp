#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int cnt[N];

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    memset(cnt,0,sizeof(cnt));
    for(int i = 0;i < n;i ++)
    {
      int val;
      cin >> val;
      cnt[val] ++;
    }
    long long ans = 0;
    for(int i = 1;i <= 1e3;i ++)
      ans += 1LL * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
    for(int i = 1;i <= 1e3;i ++)
    {
      for(int j = i + 1;j <= 1e3;j ++)
      {
        int nxt = i + (j - i) * 2;
        if(nxt > 1e3)
          continue;
        ans += 1LL * cnt[i] * cnt[j] * cnt[nxt];
      }
    }
    cout << ans << endl;
  }
}