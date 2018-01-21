#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        vector<int> G[1005];
        vector<double> v;
        map<int,double>ratio;
        for(int i = 0;i < n;i++)
        {
            int p;
            cin >> p;
            v.push_back(p);
            int k;
            cin >> k;
            for(int j = 0;j < k;j++)
            {
                int x;
                cin >> x;
                G[i].push_back(x);
            }
        }
        for(int i = 0;i < m;i++)
        {
            int kind;
            double ra;
            cin >> kind >> ra;
            if(ratio.count(kind))
                ratio[kind] = max(ratio[kind],ra);
            else
                ratio[kind] = ra;
        }
        double ans = 0;
        for(int i = 0;i < n;i++)
        {
            double add = 1;
            for(auto kind : G[i])
                if(ratio.count(kind))
                    add += ratio[kind];
            ans = max(ans,add * v[i]);
        }
        printf("%.4lf\n",ans);
    }
}