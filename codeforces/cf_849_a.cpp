// #include<bits/stdc++.h>
// using namespace std;


// //thanks to pyf ...
// //thanks to qhl ...
// int a[1000];
// set<int>s;
// int main()
// {
// 	int n;
// 	while (cin >> n)
// 	{
// 		for (int i = 1; i <= n; i++)
// 			cin >> a[i];
// 		if(a[1] % 2 && a[n] % 2 && n % 2)
// 			cout << "Yes" << endl;
// 		else
// 			cout << "No" << endl;
// 	}
// }

#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...
int a[1000];
set<int>s;
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int flag = 1;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] % 2 == 0)
			{
				flag = 0;
				break;
			}
			int j;
			for (j = i; j <= n; j += 2)
				if (a[j] % 2 && (j + 1 > n || a[j + 1] % 2))
					break;
			if (j > n)
			{
				flag = 0;
				break;
			}
			cnt ++;
			i = j;
		}
		if (!flag || cnt % 2 == 0)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
}
