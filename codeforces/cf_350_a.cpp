#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int correct_Max = -1, correct_Min = 999999, wrong_Min = 9999999;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			correct_Min = min(correct_Min, x);
			correct_Max = max(correct_Max, x);
		}
		for (int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			wrong_Min = min(wrong_Min, x);
		}
		int ans = max(correct_Max, correct_Min * 2);
		if (ans >= wrong_Min)
			cout << - 1 << endl;
		else
			cout << ans << endl;
	}
}