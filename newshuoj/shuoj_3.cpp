#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


typedef long long ll;

ll dfs(ll cur)
{
	if(cur==1)
		return 0;
	else 
		return dfs(1) + dfs(cur - 1) + cur-1;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		ll ans = dfs(n);
		if(ans == 0)
			cout << "Mission Complete!" << endl;
		else if( ans == 1)
			cout << "Needs at least " << ans << " ATP!" << endl;
		else
			cout << "Needs at least " << ans << " ATPs!" << endl;
	}
}
