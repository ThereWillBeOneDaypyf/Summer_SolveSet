#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int n;
	while(cin >> n)
	{
		long long ans = n;
		for(int i = 1;i<n;i++)
			ans += i * (n - i);
		cout << ans << endl;
	}
}
