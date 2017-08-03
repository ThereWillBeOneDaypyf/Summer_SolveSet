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
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;
const long long MOD = 998244353;

int vis[N];
int prime[N];
int prime_cnt = 0;
long long ans[N];
void get_prime()
{
	vis[1] = 1;
	for (int i = 2; i < N; i++)
	{
		if (!vis[i]) prime[prime_cnt ++ ] = i;
		for (int j = 0; j < prime_cnt && i * prime[j] < N; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}
ll tar[N];
ll k ;
void init(ll l,ll r)
{
	for(ll i = 0;i<=r-l+1;i++)
		tar[i] = l + i,ans[i] = 1;
}
void get_ans(ll l, ll r)
{
	CLR(vis, 0);
	init(l,r);
	for (ll  i = 0; i < prime_cnt; i++)
	{
		if (prime[i] > r)
			break;
		ll j = l / prime[i];
		if (l % prime[i])
			j ++;
		if (j == 1)
			j ++;
		//    ll st,ed;
		//    st = (l - 1) / prime[i] + 1;
		//    ed = r / prime[i];
		//for(ll j = st;j <= ed;j++)
		for (; j * prime[i] <= r; j++)
		{
			//            if(j <= 1)
			//                continue;
			vis[j*prime[i]- l] = 1;
			long long temp = 0;
			while(tar[j*prime[i] - l] % prime[i] == 0)
			{
				temp ++ ,tar[j * prime[i] - l] /= prime[i];
			}
			ans[j*prime[i] - l] = ((ans[j*prime[i] - l] % MOD) * (((1LL*temp % MOD * k % MOD) % MOD)+1LL)%MOD) % MOD;
		}
	}
	for(int i = 0;i<=(r-l);i++)
		if(tar[i] != 1)
			ans[i] = (ans[i] * (k + 1)) % MOD;
}
int main()
{
	ll T;
	scanf("%lld",&T);
	get_prime();
	while(T--)
	{
		ll l,r;
		ll res = 0;
		scanf("%lld%lld%lld",&l,&r,&k);
		if(l == 1)
		{
			l ++;
			res ++;
		}
		get_ans(l,r);
		for(long long i = 0;i<=(r-l);i++)
			res = (res % MOD + ans[i] % MOD + MOD) % MOD;
		printf("%lld\n",res % MOD);
	}    
}

