#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int a,b,c;
	while(cin >> a >> b >> c)
	{
		int sum  = a + b  + c;
		cout << sum - max(a,max(b,c)) << endl;
	}
}
