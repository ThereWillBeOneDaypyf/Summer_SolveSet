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

int dp[N];
int a[N];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			dp[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (a[j] < a[i])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		int Max = 0;
		for (int i = 0; i < n; i++)
			Max = max(Max, dp[i]);
		cout << Max << endl;
	}
}