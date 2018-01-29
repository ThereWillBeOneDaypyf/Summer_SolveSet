#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        vector<int> v;
        v.assign(n + 1,0);
        for(int i = 0;i < n;i++)
        {
            int x;
            scanf("%d",&x);
            v[i + 1] = x;
        }
        for(int i = 0;i < m;i++)
        {
            int op,l,r;
            scanf("%d%d%d",&op,&l,&r);
            if(op == 1)
            {
                int tar,val;
                scanf("%d%d",&tar,&val);
                for(int j = l;j <= r;j++)
                    if(v[j] == tar)
                        v[j] = val;
            }
            else
            {
                vector<int> temp;
                int k;
                scanf("%d",&k);
                for(int j = l;j <= r;j++)
                    temp.push_back(v[j]);
                sort(temp.begin(),temp.end());
                printf("%d\n",temp[k - 1]);
            }
        }
    }
}