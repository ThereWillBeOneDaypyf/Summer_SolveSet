#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		cin >> n;
		if((n-1)%2)
			cout << "Bad" << endl;
		else
			cout << "Balanced" << endl;
	} 
}
