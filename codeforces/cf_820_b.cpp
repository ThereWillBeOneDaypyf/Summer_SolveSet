#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	long double n,a;
	while(cin >> n >> a)
	{
		long double per = 180*1.0/(n);
		long double ans = a / per;
		long long fianl = (long long)floor(ans + 0.5);
		if(fianl == 0)
			fianl = 1;
		if(2+fianl >n)
			fianl = n-2;
		cout << 2 << " " << 1 << " " << 2 + fianl << endl;
	}
}
