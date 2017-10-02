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

int cnt[26];
int main()
{
	string s;
	while (cin >> s)
	{
		memset(cnt, 0, sizeof(cnt));
		for (auto & op : s)
			op = tolower(op);
		for (auto op : s)
			cnt[op - 'a'] ++;
		sort(cnt, cnt + 26, [](int a, int b) {return a < b;});
		long long ans = 0;
		for (int i = 0; i < 26; i++)
			ans += 1LL * (i + 1) * cnt[i];
		cout << ans << endl;
	}
}