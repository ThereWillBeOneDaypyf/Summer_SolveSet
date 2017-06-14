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
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int,int> PII;
typedef long long ll;

const int N = 1e5+5;

int dfs(int n,int m) // n ping guo m pan zi
{
	if(n == 0 || m == 0)
		return 1;
	if(n==1 || m==1)
		return 1;
	if(m > n)
		return dfs(n,n);
	else return dfs(n,m-1) + dfs(n-m,m); // kong yi ge pan zi || bu kong 
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		cout << dfs(n,m) << endl;
	}
}
