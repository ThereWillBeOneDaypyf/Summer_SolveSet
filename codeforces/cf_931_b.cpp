#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,a,b;
  while(cin >> n >> a >> b)
  {
    if(a > b)
      swap(a,b);
    int mid = n / 2;
    if(a <= mid && b > mid)
    {
      cout << "Final!" << endl;
      continue;
    }
    a--,b--;
    int res = a ^ b;
    for(int i = 10;i >= 0;i --)
    {
      if(res & (1 << i))
      {
        cout << (i + 1) << endl;
        break;
      }
    }
  }
}