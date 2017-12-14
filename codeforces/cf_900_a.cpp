#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			if (x < 0)
				cnt1 ++;
			else
				cnt2 ++;
		}
		if (cnt1 <= 1 || cnt2 <= 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}