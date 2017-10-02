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

int main()
{
	ios :: sync_with_stdio(false);
	vector<pair<int, int >  >v;
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		int ans = 0;
		int cnt = 0;
		stack<int>st;
		for (int i = 0; i < n; i++)
		{
			int pos = v[i].first;
			int dir = v[i].second;
			if (dir)
				st.push(pos);
			else
			{
				while (!st.empty() && st.top() < pos)
					st.pop();
				if (st.empty())
					ans ++;
			}
		}
		cout << ans + st.size() << endl;
	}
}