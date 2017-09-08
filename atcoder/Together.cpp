#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
const int N = 1e5 + 7;
int cnt[N];
int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			cnt[x] ++;
		}
		int ans = cnt[0] + cnt[1];
		for (int i = 1; i <= 1e5; i++)
			ans = max(ans, cnt[i] + cnt[i - 1] + cnt[i + 1]);
		cout << ans << endl;
	}
}