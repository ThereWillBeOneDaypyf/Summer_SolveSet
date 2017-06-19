#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int a[100000];
int main()
{
	int n;
	int T;
	cin >> T;
	int ka = 0;
	while(T-- )
	{
		cin >> n;
		for(int i =0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		cout << "Case #" << ++ ka << ":";
		for(int i =0 ;i<n;i++)
			cout << " " << a[i] ;
		cout << endl;
	}
}
