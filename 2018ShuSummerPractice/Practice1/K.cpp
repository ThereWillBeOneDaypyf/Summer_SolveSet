#include<bits/stdc++.h>
using namespace std;

char s[22];
int cnt[26];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        memset(cnt,0,sizeof(cnt));
        for(int i = 0;i < n;i ++)
            cnt[s[i] - 'a'] ++;
        int single = 0;
        for(int i = 0;i < 26;i ++)
            if(cnt[i] % 2)
                single ++;
        if(single > 1)
        {
            printf("0\n");
            continue;
        }
        else 
        {
            int l = 0;
            for(int i = 0;i < 26;i ++)
            {
                for(int j = 0;j < cnt[i] / 2;j ++)
                    s[l++] = ('a' + i);
            }
            long long ans = 1;
            for(int i = 1;i <= l;i ++)
                ans *= 1LL * i;
            for(int i = 0;i < 26;i ++)
            {
                long long cur = 1;
                for(int j  = 1;j <= cnt[i] / 2;j ++)
                    cur *= 1LL * j;
                ans /= cur;
            }
            printf("%lld\n",ans);
        }
    }
}