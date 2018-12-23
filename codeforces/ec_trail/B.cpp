#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long a;
  while(cin >> a)
  {
    if(a % 2)
      cout << -1 << endl;
    else 
    {
      while(a % 2 == 0)
      {
        a /= 2;
      }
      cout << a << endl;
    }
  }
}