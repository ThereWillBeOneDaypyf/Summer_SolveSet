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

vector<pair<int, int> > v;
int n;
int judge(int l, int r, long long tar)
{
	while (l <= r)
	{
		int mid = (l + r) / 2;
		long long cur = 1LL * mid * mid + tar;
		if (cur == n)
			return mid;
		if (cur > n)
			r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}
int main()
{
	while (cin >> n)
	{
		v.clear();
		for (int i = 0; i <= 1e5; i++)
		{
			int pos = judge(i, 1e5, 1LL * i * i);
			if (pos != -1)
				v.push_back(make_pair(i, pos));
		}
		if (v.size() == 0)
		{
			cout << "No Solution" << endl;
			continue;
		}
		for (auto temp : v)
			cout << temp.first << " " << temp.second << endl;
	}
}