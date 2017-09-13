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

int pos[4];
int a[4];
int get_num()
{
	int base = 1;
	int ans = 0;
	for (int i = 3; i >= 0; i--)
	{
		ans += base * a[pos[i]];
		base *= 10;
	}
	return ans;
}
int main()
{
	int ka = 0;
	while (cin >> a[0] >> a[1] >> a[2] >> a[3])
	{
		if (a[0] + a[1] + a[2] + a[3] == 0)
			break;
		vector<int>ans[10];
		for (int i = 0; i < 4; i++)
			pos[i] = i;
		do
		{
			if (a[pos[0]] == 0)
				continue;
			ans[a[pos[0]]].push_back(get_num());
		}
		while (next_permutation(pos, pos + 4));
		if (ka++)
			cout << endl;
		for (int i = 1; i < 10; i++)
		{
			if (ans[i].size() == 0)
				continue;
			sort(ans[i].begin(), ans[i].end());
			int cnt = unique(ans[i].begin(), ans[i].end()) - ans[i].begin();
			for (int j = 0; j < cnt; j++)
			{
				if (j)
					cout << " ";
				cout << ans[i][j] ;
			}
			cout << endl;
		}
	}
}
