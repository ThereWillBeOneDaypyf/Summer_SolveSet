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
int n, k;
int ans;
map<int, int>m;
bool judge(int sum)
{
	if (sum == 1)
		return false;
	if (sum == 2)
		return true;
	for (int i = 2; i <= sqrt(sum) + 1; i++)
		if (sum % i == 0)
			return false;
	return true;
}
void dfs(int i, int step, int sum)
{
	if (step == k)
	{
		if (judge(sum))
		{
			m[sum] = 1;
			ans ++;
		}
		return;
	}
	if (i >= n)
		return;
	dfs(i + 1, step + 1, sum + a[i]);
	dfs(i + 1, step, sum);
}

int main()
{
	while (cin >> n >> k)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		m.clear();
		ans = 0;
		dfs(0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}