#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int ans ;
		cin >> ans;
		for(int i =1 ;i<n;i++)
		{
			int x;
			cin >> x;
			ans = ans / __gcd(ans,x) * x;
		}
		cout << ans << endl;
	}
}
