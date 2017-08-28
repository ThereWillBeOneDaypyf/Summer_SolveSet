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

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;

int a[N];
int b[N];
int ans[N];
int main()
{
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		CLR(ans, 0);
		CLR(a, 0);
		CLR(b, 0);
		for (int i = 0; i < s1.length(); i++)
			a[i] = s1[i] - '0';
		for (int i = 0; i < s2.length(); i++)
			b[i] = s2[i] - '0';
		int c = 0;
		int p_a = s1.length() - 1;
		int p_b = s2.length() - 1;
		while (p_a >= 0 && p_b >= 0)
		{
			int temp_c = (c + a[p_a] + b[p_b]) / 10;
			int cur_num = (c + a[p_a] + b[p_b]) % 10;
			ans[max(p_a, p_b)] = cur_num;
			c = temp_c;
			p_a-- , p_b--;
		}
		while (p_a >= 0)
		{
			int temp_c = (c + a[p_a]) / 10;
			int cur_num = (c + a[p_a]) % 10;
			ans[p_a] = cur_num;
			c = temp_c;
			p_a --;
		}
		while (p_b >= 0)
		{
			int temp_c = (c + b[p_b]) / 10;
			int cur_num = (c + b[p_b]) % 10;
			ans[p_b] = cur_num;
			c = temp_c;
			p_b --;
		}
		printf("Case %d:\n", ++ka);
		cout << s1 << " + " << s2 << " = ";
		if (c != 0)
			printf("%d", c);
		for (int i = 0; i < max(s1.length(), s2.length()); i++)
			printf("%d", ans[i]);
		cout << endl;
		if (T)
			cout << endl;
	}
}