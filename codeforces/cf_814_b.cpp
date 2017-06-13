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
int b[N];
int ans[N];
int cnt[N];
int main()
{
	int n;
	while (cin >> n)
	{
		CLR(ans, 0)	;
		CLR(cnt, -0);
		set<int>s;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			cnt[a[i]] ++ ;
			s.insert(i);
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
			cnt[b[i]]++;
		}
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (cnt[a[i]] == 1)
			{
				ans[i] = a[i];
				s.erase(a[i]);
			}
			else if (cnt[b[i]] == 1)
			{
				ans[i] = b[i];
				s.erase(b[i]);
			}
		}
		for (int i = 1; i <= n; i++)
			if (a[i] == b[i])
			{
				ans[i] = a[i];
				s.erase(a[i]);
			}
		for (int i = 1; i <= n; i++)
		{
			if (ans[i])
				continue;
			if (a[i] != b[i])
			{
				if (s.count(a[i]))
				{
					ans[i] = a[i];
					s.erase(a[i]);
					flag ++;
				}
				else if (s.count(b[i]))
				{
					ans[i] = b[i];
					s.erase(b[i]);
				}
				else
				{
					set<int> :: iterator it;
					for (it = s.begin(); it != s.end(); it++)
					{
						ans[i] = *it;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
			i == n ? cout << ans[i] << endl : cout << ans[i] << " " ;
	}
}