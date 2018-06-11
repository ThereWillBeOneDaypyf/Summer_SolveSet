#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long n;
  while(cin >> n)
  {
    n ++;
    if(n == 1)
    {
      cout << 0 << endl;
      continue;
    }
    if(n % 2)
      cout << n << endl;
    else 
    {
      long long temp = n;
      int cnt = 0;
      cout << n / 2 << endl; 
    }
  }
}