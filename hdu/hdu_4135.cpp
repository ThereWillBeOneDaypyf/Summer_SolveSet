#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;
const int N = 1e5 + 5;

ll a[N];
int cnt = 0;

void f(int n)
{
	for(int i = 2;i*i <= n;i++)
	{
		if(n % i == 0)
		{
			a[cnt++] = i;
			while( n % i == 0)
			{
				n /= i;
			}
		}
	}	
	if( n > 1)
		a[cnt++] = n;
}
ll q[N]; 
ll rongchi(ll m)
{
	int cur = 1;
	q[0] = -1;
	for(int i =0; i< cnt;i++)
	{
		int t =  cur;
		for (int j = 0; j < t; j++)
		{
			q[cur++] = q[j] * a[i] * (-1);
		}	
	}
	ll sum = 0;
	for(int i = 1; i< cur; i++)
		sum = sum + m/q[i];
	return sum;
}	
int main()
{
	int T;
	cin >> T;
	int ka = 0;
	while(T--)
	{
		ll l,r,n;
		cin >> l >> r >> n;
		cnt = 0;
		f(n);
		cout << "Case #" << ++ ka << ": ";
		cout << (r - rongchi(r)) - (l - 1 - rongchi(l-1)) << endl;	
	}
}
