#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int p,e,i,d;
		int ka = 0;
		while(cin >> p >> e >> i >> d)
		{
			if(p == -1 && e == -1 && i == -1 && d == -1)
				break;
			p %= 23, e %= 28, i %= 33;
			int ans;
			for(ans = i ;;ans += 33)
			{
				if(ans % 23 == p && ans % 28 == e)
					break;
			}
			if(ans <= d)
				ans += (d - ans)/21252 * 21252 + 21252;
			if(ans > d)
				ans -= d;
			if(ans > 21252)
				ans = 21252;
			cout << "Case " << ++ ka << ": the next triple peak occurs in " << ans <<" days." << endl;
		}
	}
}
