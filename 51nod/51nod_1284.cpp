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
const int a[4] = {2, 3, 5, 7};
int que[N];
long long solve(long long n)
{
	que[0] = -1;
	int tot = 1;
	for (int i = 0; i < 4; i++)
	{
		int temp = tot;
		for (int j = 0; j < temp; j++)
			que[tot++] = (-1) * que[j] * a[i];
	}
	long long ans = 0;
	for (int i = 1; i < tot; i++)
		ans += n / que[i];
	return ans;
}

int main()
{
	long long n;
	while (cin >> n)
		cout << n - solve(n) << endl;
}