nclude<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

long long pow_mod(long long a,long long x)
{
	long long ans=1;
	while(x!=0)
	{
		if(x&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		x>>=1;
	}
	return ans;
}
int main()
{
	long long n,k;
	int ka = 0;
	while(cin >> n >> k)
	{
		n %= MOD;
		cout << "Case #" << ++ka << ": ";
		cout << pow_mod(n,k) << endl;
	}
}
