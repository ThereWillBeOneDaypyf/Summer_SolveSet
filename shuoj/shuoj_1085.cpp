#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thankt to qhl ...

const int N = 1e5+5;

struct Seg
{
    double l,r;
    bool operator < (const Seg &rhs) const
    {
        return l < rhs.l || (l==rhs.l && r < rhs.r);
    }
}s1[N],s2[N];


int main()
{
    int n;
    while(cin >> n)
    {
        for(int i=0;i<n;i++)
            cin >> s1[i].l >> s1[i].r;
        int m;
        cin >> m;
        for(int i=0;i<m;i++)
            cin >> s2[i].l >> s2[i].r;
        sort(s1,s1+n);
        sort(s2,s2+m);
        double ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s1[i].l <= s2[j].l)
                {
                    if(s1[i].r <= s2[j].r && s1[i].r >= s2[j].l)
                        ans += (s1[i].r - s2[j].l);
                    else if(s1[i].r >= s2[j].r)
                        ans += (s2[j].r - s2[j].l);
                }
                else
                {
                    if(s2[j].r >= s1[i].l && s2[j].r <= s1[i].r)
                        ans += (s2[j].r - s1[i].l);
                    else if(s2[j].r >= s1[i].r)
                        ans += (s1[i].r - s1[i].l);
                }
            }
        }
        printf("%.3lf\n",ans);
    }
}
