#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		int cnt[5];
		memset(cnt, 0, sizeof(cnt));
		if (a < 5)
			cnt[a] ++;
		if (b < 5)
			cnt[b] ++;
		if (c < 5)
			cnt[c] ++;
		if (cnt[1])
			cout << "YES" << endl;
		else if (cnt[2] >= 2)
			cout << "YES" << endl;
		else if (cnt[3] == 3)
			cout << "YES" << endl;
		else if (cnt[4] == 2 && cnt[2] == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}