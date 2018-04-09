#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;

int Map[N][N];
int n,m;
int a,b;
int judge()
{
  int cnt = 0;
  for(int i = 0;i < n;i ++)
  {
    for(int j = 0;j < m;j ++)
    {
      if(Map[i][j] >= a && Map[i][j] <= b)
        continue;
      cnt ++;
    }
  }
  return cnt;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    cin >> n >> m >> a >> b;
    for(int i = 0;i < n;i ++)
    {
      for(int j = 0;j < m;j ++)
      {
        cin >> Map[i][j];
      }
    }
    if(a > b)
      cout << "No Solution" << endl;
    else cout << judge() << endl;
  }
}