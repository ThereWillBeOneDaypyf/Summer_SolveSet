#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	long long n,k;
	while(cin >> n >> k )
	{ 
		long long x = n / (2*(k+1));
		long long y = k*x;
		long long z = n - x - y;
		cout << x << " " << y << " " << z << endl;
	}
}
