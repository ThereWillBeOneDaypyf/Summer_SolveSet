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

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		long long ans = 0;
		vector<int>v;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++)
		{
			if (v[i] == 1 || v[i] == 2)
				for (int j = i + 1; j < n; j++)
					ans += (v[i] + v[j]) / (1LL * v[i] * v[j]) ;
			else
				break;
		}
		printf("%d\n", ans);
	}
}