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

int main()
{
	int r, n;
	while (cin >> r >> n)
	{
		if (r == -1 && n == -1)
			break;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		int cur = 0;
		int ans = 1;
		int l = a[0];
		for (int i = 0; i < n; i++)
		{
			if (l + r >= a[i])
			{
				cur = i;
			}
			else if (a[cur] + r < a[i])
			{
				ans ++ ;
				l = a[i];
				cur = i;
			}
		}
		cout << ans << endl;
	}
}