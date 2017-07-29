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
	long long n, m;
	while (cin >> n >> m)
	{
		if (n == -1 && m == -1)
			break;
		int flag = __gcd(n, m);
		if (flag == 1)
			cout << "YES" << endl;
		else
			cout << "POOR Haha" << endl;
	}
}