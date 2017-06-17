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

int vis[N];
int prime[N];
int prime_cnt = 0;
int ans[N];
void get_prime()
{
	CLR(vis, 0);
	for (int i = 2; i < N; i++)
	{
		if (!vis[i])
		{
			prime[prime_cnt ++ ] = i;
			for (int j = 2; i * j < N; j++)
				vis[i * j] = 1;
		}
	}
}
int get_ans(ll l, ll r)
{
	CLR(vis, 0);
	int ans_cnt = 0;
	for (int i = 0; i < prime_cnt; i++)
	{
		if (prime[i] > r)
			break;
		ll j = l / prime[i];
		if (l % prime[i])
			j ++;
		if (j == 1)
			j ++;
		for (; j * prime[i] <= r; j++)
			vis[prime[i] * j - l] = 1;
	}
	for (ll i = l ; i <= r; i++)
		if (!vis[i - l])
			ans[ans_cnt++] = i;
	return ans_cnt;
}
int main()
{
	ll l, r;
	get_prime();
	while (cin >> l >> r)
	{
		if (l == 1)
			l = 2;
		int cnt = get_ans(l, r);
		int Min_dis = INF, Max_dis = 0;
		pair<ll, ll> Min , Max;
		// for (int i = 0 ; i < cnt ; i++)
		// 	cout << ans[i] << " ";
		// cout << endl;
		for (int i = 1; i < cnt; i++)
		{
			int dis = ans[i] - ans[i - 1];
			if (Min_dis > dis)
			{
				Min_dis = dis;
				Min = mp(ans[i - 1], ans[i]);
			}
			if (Max_dis < dis)
			{
				Max_dis = dis;
				Max = mp(ans[i - 1], ans[i]);
			}
		}
		if (Max_dis == 0)
			cout << "There are no adjacent primes." << endl;
		else
			cout << Min.first << "," << Min.second << " are closest, " << Max.first << "," << Max.second << " are most distant." << endl;
	}
	return 0;
}