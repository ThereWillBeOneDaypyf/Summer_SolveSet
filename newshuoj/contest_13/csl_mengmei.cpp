#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

ll get_sum(ll tar)
{
	ll cnt = 0;
	while(tar)
	{
		cnt += tar % 10;
		tar /= 10;
	}
	return cnt;
}

int main()
{
	ll n ,m;
	while(cin >> n >> m)
	{
		ll l=0,r=1e18+1,mid;
		ll ans = r+1;
		while( l <= r)
		{
			mid = (l + r)/2;
			if(mid - get_sum(mid) >= m)
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		if( ans > n)
			cout << 0 << endl;
		else
			cout << (n - ans + 1) << endl;
	}	
}
