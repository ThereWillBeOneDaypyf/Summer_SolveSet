#include <bits/stdc++.h>
using namespace std;

int Map[55][55];
map<int,char> tran;

int main()
{
  int cnt[4];
  tran[0] = 'A',tran[1] = 'B',tran[2] = 'C',tran[3] = 'D';
  while (cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3])
  {
    
    for (int k = 0; k < 4; k++)
    {
      cnt[k] --;
      for (int i = 0; i < 12; i++)
      {
        for (int j = 0; j < 50; j++)
        {
          Map[12 * k + i][j] = k;
        }
      }
    }
    for(int i = 0;i < 4;i ++)
    {
      int cur_row = 12 * (i ^ 1) + 1;
      int cur_col = 1;
      while(cnt[i])
      {
        Map[cur_row][cur_col] = i;
        cnt[i] --;
        cur_col += 2;
        if(cur_col >= 50)
          cur_col = 1,cur_row += 2;
      }
    }
    cout << 48 << " " << 50 << endl;
    for(int i = 0; i < 48;i ++)
    {
      for(int j = 0;j < 50;j ++)
      {
        cout << tran[Map[i][j]];
      }
      cout << endl; 
    }
  }
}