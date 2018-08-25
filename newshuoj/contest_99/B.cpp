#include<bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n,m;
    cin >> n >> m;
    int tar = max(n,m);
    for(int i = 1;i <= 1e5;i ++)
    {
      long long cur = 1LL * i * i;
      if((cur + 1) / 2 >= tar && cur >= n + m)
      {
        cout << i << endl;
        break;
      }
    }
  }
}