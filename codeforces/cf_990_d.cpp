#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int Map[N][N];
int n,a,b;

void solve(int x,int y)
{
  int need = n - x;
  memset(Map,0,sizeof(Map));
  for(int i = 0;i < need;i ++)
  {
    Map[i][i + 1] = 1;
    Map[i + 1][i] = 1;
  }
}

int main()
{
  while(cin >> n >> a >> b)
  {
    if(min(a,b) != 1)
    {
      cout << "NO" << endl;
      continue;
    }
    if(n == 2)
    {
      if(a == 1 && b == 1)
      {
        cout << "NO" << endl;
        continue;
      }
    }
    if(n == 3)
    {
      if(a == 1 && b == 1)
      {
        cout << "NO" << endl;
        continue;
      }
    }
    cout << "YES" << endl;
    if(a > b)
      solve(a,b);
    else
    {
      solve(b,a);
      for(int i = 0;i < n;i ++)
      {
        for(int j = 0;j < n;j ++)
        {
          if(i != j)
            Map[i][j]  ^= 1;
        }
      }
    }
    for(int i = 0;i < n;i ++) 
    {
      for(int j = 0;j < n;j ++)
        cout << Map[i][j];
      cout << endl;
    }
  }
}