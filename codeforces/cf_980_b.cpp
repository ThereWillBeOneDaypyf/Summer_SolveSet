#include<bits/stdc++.h>
using namespace std;

char Map[1000][1000];

void solve(int n,int k)
{
  int flag = 1;
  for(int i = 1;i < 3;i ++)
  {
    for(int j = 1;j < n / 2;j ++)
    {
      if(k < 2)
      {
        flag = 0;
      }
      if(!flag)
        break;
      Map[i][j] = '#';
      Map[i][n - 1 - j] = '#';
      k -= 2;
    }
  }
  for(int j = 1;j < 3;j ++)
  {
    if(k)
    {
      Map[j][n / 2] = '#';
      k --;
    }
  }
}

int main()
{
  int n,k;
  while(cin >> n >> k)
  {
    int emp = 2 * (n - 2);
    for(int i = 0;i < 4;i ++)
      for(int j = 0;j < n;j ++)
        Map[i][j] = '.';
    if(k <= 2*n)
    {
      cout << "YES" << endl;
      solve(n,k);
      for(int i = 0;i < 4;i ++)
      {
        for(int j = 0;j < n;j ++)
          cout << Map[i][j];
        cout << endl;
      }
    }
    else 
      cout << "NO" << endl;
  }
}