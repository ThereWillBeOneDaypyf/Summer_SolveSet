#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;

char Map[N][N];

int xdir[8] = {0,1,0,-1,1,1,-1,-1};
int ydir[8] = {1,0,-1,0,1,-1,1,-1};

int n,m;

int judge(int x,int y)
{
  int cnt = 0;
  for(int i = 0;i < 8;i ++)
  {
    int tx = x + xdir[i];
    int ty = y + ydir[i];
    if(tx <0 || tx >= n || ty < 0 || ty >= m)
      continue;
    if(Map[tx][ty] == '*')
      cnt++;
  }
  return cnt;
}

bool isok()
{
  for(int i = 0;i < n;i ++)
  {
    for(int j = 0;j < m;j ++)
    {
      if(Map[i][j] != '*')
      {
        int c = judge(i,j);
        int tar;
        if(Map[i][j] == '.')
          tar = 0;
        else tar = Map[i][j] - '0';
        if(c != tar)
          return false;
      }
    }
  }
  return true;
}

int main()
{
  while(cin >> n >> m)
  {
    for(int i = 0;i < n;i ++)
    {
      for(int j = 0;j < m;j ++)
      {
        cin >> Map[i][j];
      }
    }
    if(isok())
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}