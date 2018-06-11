#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  while(cin >> n >> k)
  {
    for(int i = 0;i < k; i++)
    {
      int last = n % 10;
      if(!last)
        n /= 10;
      else n --;
    }
    cout << n << endl;
  }
}