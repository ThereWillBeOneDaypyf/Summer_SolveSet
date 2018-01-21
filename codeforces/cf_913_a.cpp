#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long tar;
	long long n, m;
	while (cin >> n >> m)
	{
		if (n > 60)
		{
			cout << m << endl;
		}
		else
		{
			tar = 1;
			for (int i = 0; i < n; i++)
				tar *= 2;
			cout << m % tar << endl;
		}
	}
}
