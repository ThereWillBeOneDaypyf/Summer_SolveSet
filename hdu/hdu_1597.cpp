#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

ll cal(ll a,ll b,ll c)
{
	ll temp = floor(sqrt(b*b - 4 * a *c));
	return floor((-b + temp) / (2 * a));
}

int main()
{
	int n;
	while(cin >> n)
	{
		for(int i =0;i<n;i++)
		{
			int x;
			cin >>x;
			int j;
			for(j = 1;;j++)
			{
				if(x <= j)
					break;
				x -= j;
			}
			int ans = x % 9;
			if(!ans) ans = 9;
			cout << ans << endl;
		}
	}
}
