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

char s[N];
bool judge(int l, int r)
{
	while (l < r && s[l] == s[r])
		l ++ , r --;
	if (s[l] > s[r])
		return true;
	else return false;
}
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> s[i];
		int l = 0, r = n - 1;
		string ans;
		for (int i = 0; i < n; i++)
		{
			if (judge(l, r))
				ans += s[r--];
			else ans += s[l++];
		}
		int cnt = 0;
		for (int i = 0; i < ans.length(); i++)
		{
			cout << ans[i];
			cnt ++;
			if (cnt % 80 == 0)
				cout << endl;
		}
	}
}