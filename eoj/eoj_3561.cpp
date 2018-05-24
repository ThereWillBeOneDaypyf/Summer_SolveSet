#include<bits/stdc++.h>
using namespace std;

const int N  = 1e5 + 7;

long long a[N];
long long temp[N];
int n;

bool judge(int pos,int d)
{
    temp[pos] = a[pos];
    for(int i = pos;i >= 2;i --)
        temp[i - 1] = temp[i] - d;
    for(int i = pos;i <= n - 1;i ++)
        temp[i + 1] = temp[i] + d;
    int cnt = 0;
    for(int i = 1;i <= n;i ++)
        if(temp[i] != a[i])
            cnt ++;
    if(cnt <= 3)
    {
        for(int i = 1;i <= n;i ++)
        {
            if(i != 1)
                printf(" ");
            printf("%lld",temp[i]);
        }
        printf("\n");
        return true;
    }
    return false;
}

int main()
{
    while(scanf("%d",&n) == 1)
    {
        for(int i = 1;i <= n;i ++)
            scanf("%lld",a + i);
        map<int,int> cnt;
        for(int i = 2;i <= n;i ++)
            cnt[a[i] - a[i - 1]] ++;
        int flag = 0;
        int d = 0;
        int Max = 0;
        for(auto ele : cnt)
        {
            if(ele.second >= Max)
            {
                d = ele.first;
                Max = ele.second;
            }
        }

        for(int i = 1;i <= n;i ++)
            if(judge(i,d))
                break;
    }
}
