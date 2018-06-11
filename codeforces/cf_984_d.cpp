#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;

int dp[N][N];

int main()
{
  int n;
  while(cin >> n)
  {
    for(int i = 0;i < n;i ++)
      cin >> dp[0][i];
    for(int i = 1;i < n;i ++)
    {
      for(int j = 0;j < n - i;j ++)
      {
        dp[i][j] = dp[i - 1][j] ^ dp[i - 1][j + 1];
      }
    }
    for(int i = 1;i < n;i ++)
    {
      for(int j = 0;j < n - i; j++)
      {
        dp[i][j] = max(dp[i][j],dp[i - 1][j]);
        dp[i][j] = max(dp[i][j],dp[i - 1][j + 1]);
      }
    }
    int q;
    cin >> q;
    for(int i = 0;i < q;i ++)
    {
      int l,r;
      cin >> l >> r;
      l --, r --;
      cout << dp[r - l][l] << endl;
    }
  }
}