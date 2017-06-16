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

char s[1000][1000];
char tar[1000];
int dp[N];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		CLR(dp, 0);
		scanf("%s", tar);
		for (int i = 0; i < n; i++)
			scanf("%s", s[i]);
		dp[m] = 0;
		for (int i = m - 1; i >= 0; i--)
		{
			dp[i] = dp[i + 1] + 1;
			for (int j = 0; j < n; j++)
			{
				int len = strlen(s[j]);
				if (len <= m - i && s[j][0] == tar[i])
				{
					int pm = i;
					int pd = 0;
					while (pm < m)
					{
						if (s[j][pd] == tar[pm++])
							pd ++;
						if (pd == len)
						{
							dp[i] = min(dp[i], dp[pm] + pm - i - len);
							break;
						}
					}
				}
			}
		}
		printf("%d\n", dp[0]);
	}
	return 0;
}