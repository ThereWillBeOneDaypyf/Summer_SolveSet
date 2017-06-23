#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N = 1e5 + 5;

typedef long long ll;

ll a[N];
bool cmp(ll x,ll y)
{
	return x > y;
}
int main()
{
	ll sum ,n;
	while(cin >> sum >> n)
	{
		int cnt = 0;
		for(int i = 1;i<=sqrt(sum);i++)
		{
			if(sum % i == 0)
			{
				a[cnt++] = i;
				if(i*i!=sum)
					a[cnt++] = sum / i;
			}
		}
		sort(a,a+cnt,cmp);
		ll tot = 0;
		ll ans = -1;
		ll temp ;
		if(n % 2 ==0 )
			temp = n / 2 * (n + 1);
		else
			temp = (n+1) / 2 * n;

		for(int i = 0;i<cnt;i++)
		{
			ll c_cnt = sum / a[i];
			if( temp <= c_cnt)
			{
				ans = max(ans,a[i]);
			}
		}
		if(n > sum)
			ans = -1;
		cout << ans << endl;
	}
}
