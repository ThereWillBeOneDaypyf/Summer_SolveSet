#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e5 + 7;

int last[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		memset(last, -1, sizeof(last));
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			last[x] = i;
		}
		int ans = -1;
		for (int i = 0; i < N; i++)
		{
			if (last[i] == -1)
				continue;
			if (ans == -1 || last[ans] > last[i])
				ans = i;
		}
		cout << ans << endl;
	}
}