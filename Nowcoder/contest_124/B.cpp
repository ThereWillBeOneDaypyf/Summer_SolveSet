#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;

int a[N];

int main()
{
  int n;
  while(cin >> n)
  {
    for(int i = 0;i < n; i++)
      cin >> a[i];
    int ans = 0;
    for(int i = 0;i < n;i ++)
    {
      for(int j = 0;j < i;j ++)
      {
        if(a[i] == 2 * a[j])
        {
          ans ++;
        }
      }
    }
    cout << ans << endl;
  }
}