#include<bits/stdc++.h>
using namespace std;

int xdir[4] = {0,1,0,-1};
int ydir[4] = {1,0,-1,0};
int n,k;

char Map[105][105];

int main()
{
  while(cin >> n >> k)
  {
    for(int i = 0;i < n;i ++)
    {
      for(int j = 0;j < n;j ++)
      {
        cin >> Map[i][j];
      }
    }
    int Max = -1;
    int posx = 0,posy = 0;
    for(int i = 0;i < n;i ++)
    {
      for(int j = 0;j < n;j ++)
      {
        if(Map[i][j] == '#')
          continue;
        int left = j,right = j;
        while(left - 1 >= 0 && Map[i][left - 1] != '#')
          left --;
        while(right + 1 < n && Map[i][right + 1] != '#')
          right++;
        left = max(left,j - k + 1);
        right = min(right,j + k - 1);
        int up = i;
        int down = i;
        while(up - 1 >= 0 && Map[up - 1][j] != '#')
          up --;
        while(down + 1 < n && Map[down + 1][j] != '#')
          down ++;
        up = max(up,i - k + 1);
        down = min(down,i + k - 1);
        int cnt1 = max(0,right - left + 2 - k);
        int cnt2 = max(0,down - up + 2 - k);
        if(cnt1 + cnt2 >= Max)
        {
          Max = cnt1 + cnt2;
          posx = i,posy = j;
        }
      }
    }
    cout << posx + 1 << " " << posy + 1 << endl;
  }
}
