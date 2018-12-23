#include<bits/stdc++.h>
using namespace std;

long long get_id(long long row,long long col,long long n)
{
  if((row + col) % 2 == 0)
  {
    if(row % 2)
    {
      return (col + 1) / 2;
    }
    else
    {
      return col / 2;
    }
  }
  else
  {
    if(row % 2)
      return col / 2;
    else return (col + 1) / 2;
  }
}

void debug(int n)
{
  for(int i = 1;i <= n;i ++)
  {
    for(int j = 1;j <= n;j ++)
    {
      int x = i,y = j;
      long long cnt = (x - 1) / 2;
      long long sum = cnt * n;
      long long id = get_id(x,y,n);
      if((x + y) % 2 == 0)
      {
        if(x % 2 == 0)
          id += (n + 1) / 2;
        cout << sum + id << " ";
      }
      else
      {
        if(x % 2 == 0)
          id += n / 2;
        cout << sum + id + (long long)ceil(1.0 * n * n / 2) << " ";
      }
    }
    cout << endl;
  }
}

int main()
{
  long long n,q;
  while(cin >> n >> q)
  {
    long long x,y;
    // debug(n);
    for(int i = 0;i < q;i ++)
    {
      cin >> x >> y;
      long long cnt = (x - 1) / 2;
      long long sum = cnt * n;
      long long id = get_id(x,y,n);
      if((x + y) % 2 == 0)
      {
        if(x % 2 == 0)
          id += (n + 1) / 2;
        cout << sum + id << endl;
      }
      else
      {
        if(x % 2 == 0)
          id += n / 2;
        cout << sum + id + (n * n + 1) / 2 << endl;
      }
    }
  }
}