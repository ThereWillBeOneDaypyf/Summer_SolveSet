#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  while(cin >> n)
  {
    if(n <= 2)
    {
      cout << "No" << endl;
    }
    else
    {
      if(n & 1)
      {
        cout << "Yes" << endl;
        cout << 1 << " " << (n + 1) / 2 << endl;
        cout << n - 1;
        for(int i = 1;i <= n;i ++)
        {
          if(i == (n + 1) / 2)
            continue;
          cout << " " << i;
        }
        cout << endl;
      }
      else 
      {
        cout << "Yes" << endl;
        cout << 1 << " " << n / 2 << endl;
        cout << n - 1;
        for(int i = 1;i <= n;i ++)
        {
          if(i == n / 2)
            continue;
          cout << " " << i; 
        }
        cout << endl;
      }
    }
  }
}