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

int a[N];
vector < pair<int, pair<int, int> > > ans;
int judge(int l, int r, int tar)
{
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (a[mid] == tar)
			return mid;
		if (a[mid] > tar)
			r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n - 2; i++)
		{
			for (int j = i + 1; j < n - 1; j++)
			{
				int tar = a[i] + a[j];
				int pos = judge(j + 1, n - 1, -tar);
				if (pos != -1)
					ans.push_back(make_pair(i, make_pair(j, pos)));
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i != ans.size(); i ++)
			cout << a[ans[i].first] << " " << a[ans[i].second.first] << " " << a[ans[i].second.second] << endl;
	}
}