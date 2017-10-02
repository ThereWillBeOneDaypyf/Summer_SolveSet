#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;

struct Node
{
	int l, r;
};

int main()
{
	vector<Node>v;
	int n;
	while (cin >> n)
	{
		v.clear();
		for (int i = 0; i < n; i++)
		{
			int l, r;
			cin >> l >> r;
			v.push_back({l, r});
		}
		sort(v.begin(), v.end(), [](Node a, Node b) {return a.l < b.l ;});
		int ans = 0;
		int r = v[0].r;
		for (int i = 1; i < v.size(); i++)
		{
			if (r >= v[i].r)
			{
				ans = max(ans, v[i].r - v[i].l);
			}
			else
			{
				int dis = r - v[i].l;
				ans = max(dis, ans);
				r = max(r, v[i].r);
			}
		}
		cout << ans << endl;
	}
}