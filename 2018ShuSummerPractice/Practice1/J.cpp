#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

const int N = 1e5 + 7;


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        long long ans = 1;
        for(int i =0 ;i < n;i ++)
        {
            long long x;
            scanf("%lld",&x);
            ans *= (1 + x);
            ans %= MOD;
        }
        printf("%lld\n",((ans - 1) % MOD + MOD) % MOD);
    }
}