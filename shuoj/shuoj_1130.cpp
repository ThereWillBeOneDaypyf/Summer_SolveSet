#include<iostream>
using namespace std;

//thanks to pyf ...

int main()
{
	int n;
	while(cin >> n)
	{
		int ans = 1;
		for(int i=1;i<=n;i++)
			ans *= i;
		cout << ans << endl;
	}
}