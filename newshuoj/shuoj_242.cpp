#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

const int N = 100;

ll a[N];

void f()
{
	a[1] = 3;
	a[2] = 6;
	a[3] = 6;
	for(int i = 4;i<60;i++)
	{
		a[i] = 2*a[i-2] + a[i-1];
	}
}

int main()
{
	f();
	int n;
	while(cin >> n)
	{
		cout << a[n] << endl;
	}
}
