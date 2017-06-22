#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int a,b,c,d,t;
	while(cin >> a >> b >> c >> d >> t)
	{
		int ans = 0;
		for(int i = 1;i<=t;i++)
		{
			int cnt = 0;
			if( i % a == 0)
				cnt ++;
			if( i % b == 0)
				cnt ++;
			if( i % c == 0)
				cnt ++;
			if( i % d == 0)
				cnt ++;
			ans += cnt >= 2;
		}
		cout << ans << endl;
	}
}
