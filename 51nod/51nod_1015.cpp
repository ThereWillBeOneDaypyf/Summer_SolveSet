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

bool judge(int i)
{
	vector<int>v;
	int temp = i;
	while (i)
	{
		v.push_back(i % 10);
		i /= 10;
	}
	long long ans = 0;
	for (auto x : v)
	{
		ans += pow(x, v.size());
	}
	return ans == temp;
}

int main()
{
	int m;
	while (cin >> m)
	{
		for (int i = m;; i++)
		{
			if (judge(i))
			{
				cout << i << endl;
				break;
			}
		}
	}
}