#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int n;
	while(cin >> n)
	{
		int res = sqrt(n);
		for(int a = res;a >= 1;a -- )
		{
			if(n % a == 0)
			{
				cout << a << " " << n / a << endl;
				break;
			}
		}
	}
	return 0;
}
