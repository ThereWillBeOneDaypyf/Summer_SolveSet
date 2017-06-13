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
int b[N];
int tar[N];
bool judge(int l)
{
	for (int i = 1; i < l; i++)
		if (tar[i - 1] > tar[i])
			return false;
	return true;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		map<int, int>cal;
		int pos = 0;
		int flag = 0;
		int l = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == 0)
				pos = i;
			if (a[i] != 0)
				tar[l++] = a[i];
		}
		for (int i = 0 ; i < m; i++)
			cin >> b[i];
		for (int i = 0; i < m; i++)
			if (!cal.count(b[i]))
				cal[b[i]] = 1;
		if (cal.size() > 1)
			flag = 1;
		else
		{
			if (judge(l))
			{
				a[pos] = b[0];
				for (int i = 1; i < n; i++)
					if (a[i - 1] > a[i])
						flag = 1;
			}
			else flag = 1;
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}