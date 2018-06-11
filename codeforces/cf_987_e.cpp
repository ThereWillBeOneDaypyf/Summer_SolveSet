#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int b[N];
int n;
int lowbit(int x)
{
  return x & (-x);
}

void add(int x)
{
  while(x <= n)
  {
    b[x] ++;
    x += lowbit(x);
  }
}

int query(int x)
{
  int sum = 0;
  while(x > 0)
  {
    sum += b[x];
    x -= lowbit(x);
  }
  return sum;
}

int main()
{
  while(cin >> n)
  {
    long long ans = 0;
    for(int i = 1;i <= n;i ++)
    {
      int x;
      cin >> x;
      ans += query(n) - query(x);
      add(x);
    }
    ans = 7 * n + 1 - ans;
    if(ans & 1)
      cout << "Petr" << endl;
    else cout << "Um_nik" << endl;
  }
}