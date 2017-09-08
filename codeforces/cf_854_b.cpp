#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int Min , Max;
		if (k == n || k == 0)
			Min = 0;
		else
			Min = 1;
		int need_k = n / 3;
		Max = need_k * 2;
		if (k < need_k)
			Max -= (need_k - k) * 2;
		else if (k > need_k)
		{
			if (n % 3 == 1)
				k --;
			else if (n % 3 == 2)
			{
				k -- ;
				Max ++;
			}
			Max -= (k - need_k);
		}
		cout << Min << " " << Max << endl;
	}
}