#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e5 + 7;

pair<long long, int> BIT[N];
int n;
int lowbit(int x)
{
	return x & (-x);
}
void update(int x, int val)
{
	while (x < N)
	{
		BIT[x].first += val;
		BIT[x].second ++;
		x += lowbit(x);
	}
}
pair<long long, int> query(int x)
{
	pair<long long, int>ans;
	while (x > 0)
	{
		ans.first += BIT[x].first;
		ans.second += BIT[x].second;
		x -= lowbit(x);
	}
	return ans;
}
struct Node
{
	int v, pos;
	bool operator < (const Node & rhs) const
	{
		return v < rhs.v;
	}
};
vector<Node>v;
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		v.clear();
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v.push_back({x, y});
		}
		memset(BIT, 0, sizeof(BIT));
		sort(v.begin(), v.end());
		long long ans = 0;
		for (int i = 0; i < v.size(); i++)
		{
			int val = v[i].v, pos = v[i].pos;
			pair<long long, int>temp1 = query(pos), temp2 = query(N - 1);
			long long temp = val * (pos * temp1.second - temp1.first) + val * (temp2.first - temp1.first - pos * (temp2.second - temp1.second));
			ans += temp;
			update(pos, pos);
		}
		printf("%lld\n", ans);
	}
}