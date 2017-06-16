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

int prime[N];
int vis[N];
int odd_prime_cnt = 0;
void f()
{
	CLR(prime, 0);
	CLR(vis, 0);
	vis[1] = 1;
	vis[0] = 1;
	for (int i = 2; i < N; i++)
	{
		if (!vis[i])
		{
			if (i % 2 == 1)
				prime[odd_prime_cnt++] = i;
			for (int j = 2; j * i < N; j++)
				vis[j * i] = 1;
		}
	}
}
void solve(int n)
{
	for (int i = 0; i < odd_prime_cnt; i++)
	{
		if (prime[i] >= n)
			break;
		if (((n - prime[i]) % 2 == 1) && !vis[n - prime[i]])
		{
			cout << n << " = " << prime[i] << " + " << n - prime[i] << endl;
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong." << endl;
}
int main()
{
	f();
	int n;
	while (cin >> n && n)
	{
		solve(n);
	}
}