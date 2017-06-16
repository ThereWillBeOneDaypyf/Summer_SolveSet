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
	int n;
	while (cin >> n)
	{
		CLR(a, 0);
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int tar = a[1];
		sort(a + 1, a + n + 1);
		int pos = -1;
		for (int i = 1; i <= n; i++)
			if (a[i] == tar && a[i + 1] != tar)
			{
				pos = i;
				break;
			}
		if (pos % 2 == 1)
			pos --;
		int ans = 0;
		while (pos > 1)
		{
			pos /= 2;
			ans ++;
		}
		cout << ans << endl;
	}
}