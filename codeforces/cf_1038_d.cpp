#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  while(cin >> n)
  {
    long long sum = 0;
    int Min = 1e9 + 7;
    bool all_neg = true;
    bool all_plus = true;
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      if(x < 0)
        all_plus = false; 
      if(x > 0)
        all_neg = false;
      sum += abs(x);
      Min = min(Min,abs(x));
    }
    if(all_neg || all_plus && (n > 1))
      cout << sum - 2 * Min << endl;
    else 
      cout << sum << endl;
  }
}