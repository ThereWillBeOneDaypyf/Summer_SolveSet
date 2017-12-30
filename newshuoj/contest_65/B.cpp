#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

long long pre_sum[N];
long long cur_sum[N];
long long k;
struct Node
{
	int pos, val;
	bool operator < (const Node & rhs) const
	{
		return val + k * pos < rhs.val + k * rhs.pos;
	}
};
vector<Node> v;
int main()
{
	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		int n;
		long long S;
		long long temp;
		cin >> n >> S;
		temp = S;
		v.clear();
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			v.push_back({i, x});
		}
		sort(v.begin(), v.end());
		int l = 0, r = n;
		long long ans = 0;
		long long cnt = 0;
		while (l <= r)
		{
			k = (l + r) / 2;
			sort(v.begin(), v.end());
			long long cur = 0;
			for (int i = 0; i < k; i++)
				cur += k * v[i].pos + v[i].val;
			if (cur <= S)
			{
				ans = cur;
				cnt = k;
				l = k + 1;
			}
			else
				r = k - 1;
		}
		cout << "Case #" << ++ ka << ": ";
		cout << cnt << " " << ans << endl;
	}
}