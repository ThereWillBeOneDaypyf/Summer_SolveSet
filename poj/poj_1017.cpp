#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int a[10];

bool judge()
{
	for (int i = 1;i <= 6;i++)
		if (a[i])
			return true;
	return false;
}

int main()
{
	while (cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] )
	{
		if (!judge())
			break;
		long long ans = 0;
		for (int i = 1; i<= 6;i++)
		{
			ans += i * i * a[i] ;
		}
		int tot = 0;
		for (int i = 6; i>= 1;i--)
		{
			while(ans >= i*i)
			{
				tot ++ ,ans -= i*i;
			}
		}
		cout << tot << endl;
	}
}
