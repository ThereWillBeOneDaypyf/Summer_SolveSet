#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...



int main()
{
	int n;
	while (cin >> n)
	{
		int l = 1, r = n;
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			if (i)
				cout << " ";
			if (!flag)
				cout << l ++;
			else
				cout << r --;
			flag ^= 1;
		}
		cout << endl;
	}
}