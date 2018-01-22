#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int ans = a * b + (100 - a) * c;
        printf("%.1lf\n",1.0 * ans / 100);
    }
}