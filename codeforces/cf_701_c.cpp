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
	int n;
	while (cin >> n)
	{
		string s;
		cin >> s;
		map<char, int>m;
		int cnt = 0 ;
		for (int i = 0; i < n; i++)
		{
			if (!m.count(s[i]))
			{
				m[s[i]] = 1;
				cnt ++;
			}
		}
		m.clear();
		int l = 0, r = 0;
		int cur_cnt = 0;
		int ans = INF;
		while (l <= r && r <= n)
		{
			if (cur_cnt < cnt)
			{
				if (!m.count(s[r]))
					cur_cnt++;
				m[s[r++]] ++;
			}
			else
			{
				ans = min(ans, r - l);
				m[s[l]] --;
				if (m[s[l]] == 0)
				{
					cur_cnt --;
					m.erase(s[l]);
				}
				l++;
			}
		}
		cout << ans << endl;
	}
}