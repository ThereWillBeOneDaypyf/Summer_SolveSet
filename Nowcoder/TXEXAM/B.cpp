#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e3 + 7;

long long  C[N][N];

void init_C()
{
  memset(C,0,sizeof(C));
  C[0][0] = 1;
  C[1][0] = 1,C[1][1] = 1;
  for(int i = 2;i <= 1000;i ++)
  {
    C[i][0] = 1;
    for(int j = 1;j <= i;j ++)
    {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      C[i][j] %= MOD;
    }
  }
}

int main()
{
  init_C();
  int k;
  int a,x,b,y;
  while(cin >> k >> a >> x >> b >> y)
  {
    long long ans = 0;
    for(int i = 0;i <= x;i ++)
    {
      int ret = k - a * i;
      if(ret < 0)
        break;
      if(ret % b == 0)
      {
        int j = ret / b;
        if(j > y)
          continue;
        ans += C[x][i] * C[y][j];
        ans %= MOD;
      }
    }
    cout << ans << endl;
  }
}