#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int Max[N];
int Min[N];
int a[N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;i ++)
            scanf("%d",a + i);
        int ans = 0;
        Max[0] = 0;
        Min[n + 1] = 1e6 + 1;
        for(int i = 1;i <= n;i ++)
            Max[i] = max(a[i],Max[i - 1]);
        for(int i = n;i >= 1;i --)
            Min[i] = min(a[i],Min[i + 1]);
        for(int i = 2;i < n;i ++)
        {
            if(Max[i - 1] <= a[i] && a[i] <= Min[i + 1])
                ans ++;
        }
        printf("%d\n",ans);
    }
}