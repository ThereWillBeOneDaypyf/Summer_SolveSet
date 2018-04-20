#include<bits/stdc++.h>
using namespace std;

long long solve(long long a)
{
  if(a == 0)
    return 0;
  if(a % 2)
    return 2 * solve(a / 2) + a / 2 + 1;
  else return 2 * solve(a / 2) + a / 2;
}

int main()
{
  long long n;
  while(cin >> n)
    cout << solve(n - 1) << endl;
}