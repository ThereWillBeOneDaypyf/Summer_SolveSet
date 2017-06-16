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
int judge(int n)
{
	map<int, int> m;
	int undefine = 0;
	queue<int>pos;
	for (int i = 1; i <= n; i++)
	{
		char x;
		cin >> x;
		if (x == '?')
		{
			undefine ++;
			pos.push(i);
		}
		else
		{
			int y;
			cin >> y;
			if (x == 'O')
			{
				if (!m.count(y))
					if (undefine < 1)
						return i ;
					else
						undefine --, pos.pop();
				else
				{
					m[y] --;
					if (m[y] == 0)
						m.erase(y);
				}
			}
			else
			{
				if (m.count(y))
					if (undefine < 1)
						return pos.front();
					else
						undefine --;
				else
					m[y] ++;
			}
		}
	}
	return -1;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int cnt = judge(n);
		if (cnt != -1)
			for (int i = cnt + 1; i <= n; i++)
			{
				char x;
				int y;
				cin >> x;
				if (x != '?')
					cin >> y;
			}
		cout << cnt << endl;
	}
}