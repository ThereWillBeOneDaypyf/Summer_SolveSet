#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

ll inv(ll a, ll p)
{
    ll d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}

int main()
{
  long long n;
  while(cin >> n)
  {
    n %= MOD;
    long long ans = n * (n + 1);
    ans %= MOD;
    ans *= (2 * n  + 1);
    ans  %= MOD;
    ans *= inv(6,MOD);
    ans %= MOD; 
    cout << ans << endl;
  }
}