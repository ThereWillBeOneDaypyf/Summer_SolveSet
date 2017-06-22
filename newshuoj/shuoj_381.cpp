#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int a[10];

int main()
{
	while(cin >> a[0])
	{
		for(int i = 1;i<8;i++)
			cin >> a[i];
		for(int i =0 ;i<7;i++)
		{
			for(int j = 0;j<8 - i - 1;j++)
			{
				if(a[j] > a[j+1])
				{
					cout << j+1 << " " << 0 << endl;
					cout << j+2 << " " << j+1 << endl;
					cout << 0 << " " << j+2 << endl;
					swap(a[j+1],a[j]);
				}
			}
		}
		cout << -1 << endl;
	}
	return 0;
}
