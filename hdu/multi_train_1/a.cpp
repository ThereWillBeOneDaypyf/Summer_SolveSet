#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

int main()
{
	int n;
	int ka = 0;
	while(cin >> n)
	{
		cout << "Case #" << ++ka << ": ";
		double x = log(10) / log(2);
		int ans = n / x;
		cout << ans << endl;
	}
}
