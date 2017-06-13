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


struct Node
{
	int v, w;
	double get_k() const
	{
		return (double) v / w;
	}
	bool operator < (const Node &rhs) const
	{
		return get_k() > rhs.get_k();
	}
} a[N];

int dp[N];

int main()
{
	int n, c;
	int ka = 0;
	while (cin >> n >> c)
	{
		for (int i = 0 ; i < n; i++)
			cin >> a[i].v;
		for (int i = 0; i < n; i++)
			cin >> a[i].w;
		// sort(a,a+n);
		CLR(dp, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = c; j >= a[i].w; j--)
			{
				dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v);
			}
		}
		cout << "Case " << ++ka << ":" ;
		cout << dp[c] << endl;
	}
}