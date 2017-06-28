#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

int a[N];

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i =0 ;i<n;i++)
		{
			cin >> a[i];
		}
		sort(a,a+n);
		if(n == 1)
		{
			cout << a[0] << endl;
			continue;
		}
		else if(n == 2)
		{
			cout << a[1] << endl;
			continue;
		}
		int ans =0 ;
		int i = n - 1;
		for(i = n-1;i>=3;i-=2)
		{
			int res = (a[0] + a[1] + a[1] + a[i]);
			res = min(res ,a[0] + a[i] + a[0] + a[i-1]);
			ans += res ;
		}
		if(i == 2)
		{
			int res = (a[0] + a[1] + a[i]);
			res = min(res ,a[0] + a[1] + a[i]);
			ans += res;
		}			
		else if( i == 1)
		{
			ans += a[1];
		}
		else if(i == 0)
		{
			ans += a[0];
		}
		cout << ans << endl;
	}
}
