#include<bits/stdc++.h>
using namespace std;

int n,m;

bool Map[30][30];
int pre_sum[30][30][2];


int main()
{
  while(cin >> n >> m)
  {
    memset(Map,0,sizeof(Map));
    memset(pre_sum,0,sizeof(pre_sum));
    for(int i = 1;i <= n;i ++)
    {
      for(int j = 1;j <= m; j++)
      {
        char op;
        cin >> op;
        Map[i][j] = (op == '0');
      }
    }
    for(int i = 1;i <= n;i ++)
    {
      for(int j = 1;j <= m;j ++)
      {
        pre_sum[i][j][0] += pre_sum[i][j - 1][0] + Map[i][j];
        pre_sum[i][j][1] += pre_sum[i - 1][j][1] + Map[i][j];
      }
    }
    int ans = 0;
    for(int i = n;i >= 0;i --)
    {
      for(int j = m;j >= 0;j --)
      {
          for(int x = 1;x <= n;x ++)
          {
            for(int y = 1;y <= m;y ++)
            {
              int tx = x + i;
              int ty = y + j;
              if(tx > n || ty > m)
                continue;
              int sum = 0;
              for(int k = x;k <= tx;k ++)
                sum += pre_sum[k][ty][0] - pre_sum[k][y - 1][0];
              if(sum != ((i + 1) * (j + 1)))
                continue;
              ans = max(ans,(i + j + 2) * 2);
            }
          }
      }
    }
    cout << ans << endl;
  }
}
