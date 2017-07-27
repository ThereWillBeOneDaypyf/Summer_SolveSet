#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	long long n ,m;
	int ka = 0;
	while(scanf("%lld%lld",&n,&m)==2)
	{
		cout << "Case #" << ++ ka << ": ";
		long long cnt = floor(double(1.0 * (m-n) / (n-1)));
		long long cur = 0;
		if(m <= n)
		{
			cout << m << endl;
			continue;
		}
		if(cnt % 2)
			cur = n-1;
		else
			cur = n;
		long long ans = (m-n) % (n-1);
		if(ans == 0)
			cout << cur << endl;
		else
			cout << ans << endl;
	}
}
