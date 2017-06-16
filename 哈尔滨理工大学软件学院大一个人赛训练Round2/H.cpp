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
ll k ;
int n;
int flag = 0;
void dfs(int i, ll sum)
{
	if (flag)
		return ;
	if (i >= n)
	{
		if (sum == k)
			flag = 1;
		return;
	}
	dfs(i + 1, sum);
	dfs(i + 1, sum + a[i]);
}
int main()
{
	while (cin >> n >> k)
	{
		flag = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		dfs(0, 0);
		if (!flag)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
}