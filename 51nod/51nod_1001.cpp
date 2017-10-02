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
	map<int, int> m;
	int n, k;
	while (cin >> k >> n)
	{
		m.clear();
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			m[x] ++;
		}
		int cnt = 0;
		for (auto temp : m)
		{
			if (m.count(k - temp.first))
			{
				cnt ++;
				if (temp.first < k - temp.first)
					cout << temp.first << " " << k - temp.first << endl;
			}
		}
		if (!cnt)
			cout << "No Solution" << endl;
	}
}