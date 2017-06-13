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

int fa[N];

void init()
{
	for (int i = 0; i < N; i++)
		fa[i] = i;
}
int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		fa[a] = fa[b];
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		init();
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			if (find(a) != find(b))
				merge(a, b);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i == find(i))
				ans ++;
		}
		cout << ans << endl;
	}
}



