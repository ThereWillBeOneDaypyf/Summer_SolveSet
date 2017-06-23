#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

ll a[100];

void f()
{
	memset(a,0,sizeof(a));
	a[1] = 1;
	a[2] = 2;
	for(int i = 3;i <= 50;i++)
		a[i] = a[i-1] + a[i-2];
}

int main()
{
	int n;
	f();
	while(cin >> n)
	{
		cout << a[n] << endl;
	}

}
