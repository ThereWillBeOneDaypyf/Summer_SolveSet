#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		int ans = 1;
		for(int i = 1;i<= min(n,m);i++)
			ans *= i;
		cout << ans << endl;
	}
}
