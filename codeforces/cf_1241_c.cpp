#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int q;
	cin >> q;
	while(q --)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0;i < n;i ++)
			cin >> v[i], v[i] /= 100;
		int x, a, y, b;
		cin >> x >> a >> y >> b;
		long long k;
		cin >> k;
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int l = 1, r = n;
		int ans = -1;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			long long sum = 0;
			int ind = 0;
			vector<int> bufs;
			for(int i = 0;i < mid; i ++)
			{
				int buf = 0;
				if((i + 1) % a == 0)
					buf += x;
				if((i + 1) % b == 0)
					buf += y;
				bufs.push_back(buf);	
			}
			sort(bufs.begin(), bufs.end(), [](int a, int b) { return a > b; });
			for(int i = 0;i < mid; i ++)
				sum += 1LL * bufs[i] * v[i];
			if(sum >= k)
			{
				if(ans == -1)
					ans = mid;
				else ans = min(ans, mid);
				r = mid - 1;
			}
			else 
				l = mid + 1;
		}
		cout << ans << endl;
	}
}
