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
	map<int, int>last_I;
	map<int, int>last_O;
	vector<int>pos;
	for (int i = 1; i <= n; i++)
	{
		char x;
		cin >> x;
		if (x == '?')
		{
			undefine ++;
			pos.push_back(i);
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
					{
						vector<int> :: iterator it;
						it = lower_bound(pos.begin(), pos.end(), last_O[y]);
						if (it != pos.end())
							pos.erase(it);
						else
							return i;
						undefine --;
						last_O[y] = i;
					}
				else
				{
					m[y] --;
					last_O[y] = i;
					if (m[y] == 0)
						m.erase(y);
				}
			}
			else
			{
				if (m.count(y))
					if (undefine < 1)
						return i;
					else
					{
						vector<int> :: iterator it;
						it = lower_bound(pos.begin(), pos.end(), last_I[y]);
						if (it != pos.end())
							pos.erase(it);
						else
							return i;
						undefine --;
						last_I[y] = i;
					}
				else
					m[y] ++, last_I[y] = i;
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
/*
5
I 1
O 1
?
I 1
I 1
 */