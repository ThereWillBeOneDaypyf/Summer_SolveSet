#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
int main()
{
	string s;
	while (cin >> s)
	{
		priority_queue<int>q1, q2;
		int part1 = 0, part2 = 0;
		for (int i = 0; i < 3; i++)
		{
			part1 += s[i] - '0';
			q1.push(9 - s[i] + '0');
			q2.push(s[i] - '0');
		}
		for (int i = 3; i < 6; i++)
		{
			part2 += s[i] - '0';
			q2.push(9 - s[i] + '0');
			q1.push(s[i] - '0');
		}
		int ans = 0;
		if (part1 == part2)
			cout << 0 << endl;
		else if (part1 < part2)
		{
			int dif = part2 - part1;
			while (!q1.empty())
			{
				int add = q1.top();
				q1.pop();
				ans ++;
				if (add >= dif)
					break;
				else dif -= add;
			}
			cout << ans << endl;
		}
		else
		{
			int dif = part1 - part2;
			while (!q2.empty())
			{
				int add = q2.top();
				q2.pop();
				ans ++;
				if (add >= dif)
					break;
				else dif -= add;
			}
			cout << ans << endl;
		}
	}
}