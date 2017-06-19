#include<bits/stdc++.h>

using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

int main()
{
	ll n;
	while(cin >> n)
	{
		if(n == 1)
			cout << -1 << endl;
		else
			cout << n << " " << n+1 << " " << n*(n+1) << endl; 
	}
}
