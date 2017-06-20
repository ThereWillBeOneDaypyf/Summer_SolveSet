#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

ll mod;


ll pow_mod(ll x,ll a)
{
	if(a == 0)
		return 1;
	ll ans = pow_mod(x,a/2);
	ll res = ans * ans % mod;
	if(a % 2 == 1)
		res = res * x % mod;
	return res;
}

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		mod = n;
		ll x = pow_mod(m,m);
		cout << __gcd(n,(int)x) << endl;
	}
}

