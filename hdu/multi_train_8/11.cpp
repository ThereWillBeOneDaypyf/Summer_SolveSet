#include <iostream>  
#include <string.h>  
#include <stdio.h>  

using namespace std;  
typedef long long LL;  
const LL p = 1e9 + 7;
const LL MOD = 1e9 + 7;
long long C[2005][2005];
void fun()
{
	C[0][0] = 1;
	C[1][0] = C[1][1] = 1;
	for(int i = 2;i< 2005;i++)
	{
		C[i][0] = 1;
		for(int j = 1;j<=i;j++)
		{
			C[i][j] = C[i-1][j-1] + C[i-1][j] % MOD; 
			C[i][j] %= MOD;
		}
	}
}

LL n,m;
long long A[3000];
long long dp[2005][2005];
void f()
{
	A[0] = 1;
	for(int i = 1;i<2010;i++)
		A[i] = A[i-1] * i % MOD;
}
LL quick_mod(LL a, LL b)  
{  
	long long temp = 1;
	long long db=b;
	long long da=a;
	while(db>0)
	{
		if(db&1) temp=(temp*da)%MOD;
		da=(da*da)%MOD;
		db>>=1;
	}
	return dp[a][b]=temp;
}  

int main()  
{  
	int T;  
	scanf("%d", &T);  
	fun(),f();
	memset(dp,0,sizeof(dp));
	while(T--)  
	{  
		long long n,m;
		scanf("%lld%lld",&n,&m);
		long long ans = 0;
		if(m > n)
		{
			for(int i = 1;i<n;i++)
			{
				long long temp = 0;
				int flag = -1;
				for(int j = 0;j<=i;j++)
				{
					flag *= -1;
					temp = temp + (MOD + flag * ((C[i][j]* quick_mod(i-j,n))) % MOD) % MOD; 
					temp = (temp + MOD ) % MOD;
				}
				ans = ans + (((temp * C[m][i]) % MOD) * quick_mod(m-i,n))%MOD;
				ans %= MOD;
			}
			ans = ans + (((C[m][n] * A[n]) % MOD) * quick_mod(m-n,n))%MOD ;
			ans %= MOD;
		}
		else
		{
			for(int i = 1;i<=m;i++)
			{
				long long temp = 0;
				int flag = -1;
				for(int j=0;j<=i;j++)
				{
					flag *= -1;
					temp = temp + ((flag * ((C[i][j] % MOD) * quick_mod(i-j,n) % MOD)+MOD)%MOD)%MOD;
					temp = (temp + MOD) % MOD;
				}
				ans = ans + ((temp * C[m][i] % MOD) * quick_mod(m-i,n)) % MOD;
				ans %= MOD;
			}
		}
		printf("%lld\n",(ans + MOD) % MOD);
	}  
	return 0;  
}  
