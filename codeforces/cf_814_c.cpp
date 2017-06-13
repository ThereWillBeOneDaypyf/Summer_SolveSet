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

int ans[1505][30];

int rular(int m, char x, string s)
{
	int l = -1, r = 0;
	int cur_used = 0;
	int cur_Max = 0;
	int cur_ans = 0;
	while (l <= r && r < s.length())
	{
		if (s[r] == x)
		{
			cur_ans++;
			cur_Max = max(cur_ans, cur_Max);
			r++;
		}
		else
		{
			if (cur_used < m)
			{
				cur_used++;
				cur_ans ++;
				cur_Max = max(cur_ans, cur_Max);
				r++;
			}
			else
			{
				l++;
				if (s[l] != x)
				{
					cur_used -- ;
				}
				cur_ans -- ;
			}
		}
	}
	return ans[m][x - 'a'] = cur_Max;
}
int main()
{
	int n;
	while (cin >> n)
	{
		CLR(ans, 0);
		string s;
		cin >> s;
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int l;
			char x;
			cin >> l >> x;
			if (!ans[l][x - 'a'])
				cout << rular(l, x, s) << endl;
			else
				cout << ans[l][x - 'a'] << endl;
		}
	}
}