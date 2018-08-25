#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int cnt[N];
int temp[N];
bool judge(int n,int m,int Max,int lst)
{
  int sx = n - lst + 1;
  int sy = Max - sx + 2;
  
  if(sx <= n && sy <= m && sx >= 1 && sy >= 1)
  {
    // cout << n << " " << m << " " << sx << " " << sy << endl;
    for(int i = 0;i <= Max;i ++)
      temp[i] = 0;
    for(int i = 1;i <= n;i ++)
    {
      for(int j = 1;j <= m;j ++)
      {
        int res = abs(sx - i) + abs(sy - j);
        temp[res] ++;
      }
    }
    for(int i = 0;i <= Max;i ++)
      if(temp[i] != cnt[i])
        return false;
    cout << n << " " << m << endl << sx << " " << sy << endl;
    return true;
  }
  return false;
}

int main()
{
  int t;
  ios :: sync_with_stdio(false);
  while(cin >> t)
  {
    memset(cnt,0,sizeof(cnt));
    int Max = 0;
    for(int i = 0;i < t;i ++)
    {
      int x;
      cin >> x;
      cnt[x] ++;
      Max = max(Max,x);
    }
    int lst = 1;
    for(int i = 1;i <= Max;i ++)
    {
      if(cnt[i] < 4 * i)
      {
        lst = i;
        break;
      }
    }
    int flag = 0;
    for(int i = 1;i * i <= t;i ++)
    {
      if(t % i)
        continue;
      if(judge(i,t / i,Max,lst))
      {
        flag = 1;
        break; 
      }
      if(judge(t / i, i,Max,lst))
      {
        flag = 1;
        break;
      }
    }
    if(!flag)
      cout << -1 << endl;
  }
}