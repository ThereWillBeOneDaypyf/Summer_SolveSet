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
int n, m;

int main()
{
	while (cin >> n >> m)
	{
		int ans = 0 ;
		for (int i = 0; i < m; i++)
			cin >> a[i];
		map<int, int>vis;
		for (int i = 0; i < m; i++)
		{
			int base = 1;
			while (base * a[i] <= n)
			{
				if (!vis.count(a[i]*base))
				{
					vis[base * a[i]] = 1;
					ans ++;
				}
				base++;
			}
		}
		cout << ans << endl;
	}
}