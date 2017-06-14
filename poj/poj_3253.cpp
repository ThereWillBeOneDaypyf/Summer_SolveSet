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
	while (cin >> n)
	{
		ll ans = 0;
		priority_queue<int , vector<int>  , greater<int> > q;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			q.push(x);
		}
		while (q.size() > 1)
		{
			int x = q.top();
			q.pop();
			int y = q.top();
			q.pop();
			ans += (x + y);
			q.push(x + y);
		}
		cout << ans << endl;
	}
}