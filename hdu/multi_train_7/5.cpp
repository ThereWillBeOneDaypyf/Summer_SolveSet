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

int prime[N];
int vis[N];
int cnt = 0;

void f()
{
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i < N; i++)
		if (!vis[i])
		{
			prime[cnt++] = i;
			for (int j = 1; j * i < N; j++)
				vis[i * j] = 1;
		}
}
int main()
{
	ios :: sync_with_stdio(false);
	f();
	int T;
	cin >> T;
	while (T--)
	{
		long long a;
		cin >> a;
		long long ans ;
		if (a % 2 == 0)
			ans = a / 2 + 1;
		else
			ans = a / 2 + 2;
		cout << ans << endl;
	}
}