#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;


int a[N];
int b[N];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        int cnt = 0;
        for(int i = 0;i < n;i ++)
            scanf("%d",a + i);
        int p = 0;
        for(int i = 0;i < m;i ++)
        {
            int x;
            scanf("%d",&x);
            while(p < n && a[p] < x)
                p ++;
            if(a[p] == x)
                b[cnt++] = x;
        }
        if(cnt == 0)
            printf("empty\n");
        else
        {
            for(int i = 0;i < cnt;i ++)
            {
                if(i)
                    printf(" ");
                printf("%d",b[i]);
            }
            printf("\n");
        }
    }
}