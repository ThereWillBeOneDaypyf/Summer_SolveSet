#include<bits/stdc++.h>
using namespace std;

long long cnt[10000];

int main()
{
	//freopen("1.in", "r", stdin);
	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		int n;
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			x += 500;
			cnt[x] ++;
		}
		long long ans = 0;
		if (cnt[500] >= 3)
			ans += (cnt[500] - 2) * (cnt[500] - 1) * cnt[500];
		for (int i = 0; i <= 1000; i++)
		{
			if (!cnt[i] || i == 500)
				continue;
			ans += 2LL * (cnt[i] - 1) * cnt[i] * cnt[500];
			if (i * 2 - 1000 < -500 || i * 2 - 1000 > 500)
				continue;
			ans += (cnt[i] - 1) * cnt[i] * cnt[i * 2 - 500];
		}
		for (int i = 0; i <= 1000; i++)
		{
			for (int j = 0; j <= 1000; j ++)
			{
				if (i == 500 && j == 500)
					continue;
				int reali = i - 500, realj = j - 500;
				int tar = reali + realj;
				if (tar < -500 || tar > 500)
					continue;
				if (reali == tar || realj == tar || reali == realj)
					continue;
				ans += cnt[i] * cnt[j] * cnt[tar + 500];
			}
		}
		cout << "Case #" << ++ ka << ": ";
		cout << ans << endl;
	}
}