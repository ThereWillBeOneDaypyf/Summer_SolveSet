#include<bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
long long dp[1050][1050][11];
int a[1050];

int main()
{
    int t,n;
    scanf("%d",&t);
    //freopen("1.in","r",stdin);
    //in(t);
    while(t--)
    {
        int d,sum=0;
        long long ans = 0;
        scanf("%d%d",&n,&d);
        //in(n),in(d);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            //in(a[i]);
            sum^=a[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i][0][0]=1;
            for(int j=1;j<=i;j++)
            {
                dp[i][a[j]][1]=1;
            }
        }
        for(int k=0;k<=d;k++)
            for(int i=2;i<=n;i++)
              for(int j=0;j<=1024;j++)
                    dp[i][j][k]=((dp[i-1][j^a[i]][k-1])+dp[i-1][j][k])%MOD;
        //for(int i=1;i<=n;i++)
            for(int k=0;k<=d;k++)
                ans=(dp[n][sum][k]+ans)%MOD;
        printf("%lld\n",ans);
        //out_int(ans + 1);
        //out_char('\n');
    }
    //write();
}
