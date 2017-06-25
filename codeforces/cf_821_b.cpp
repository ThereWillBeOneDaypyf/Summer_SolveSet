#include<bits/stdc++.h>
using namespace std;


typedef  long long ll;

ll m,b;

ll get_x(ll y)
{
	return abs(m*y-m*b); 
}
ll get_ans(ll x,ll y)
{
	return (x+1) * (1+y)*y /2 + (y+1) * (1+x)*x/2;
}
int main()
{
	while(cin >> m >> b)
	{
		ll ans = 0;
		for(int i = 0 ;i<= b;i++)
		{
			ll x= get_x(i);
			ans = max(get_ans(x,i),ans);
		}
		cout << ans << endl;
	}	
}
