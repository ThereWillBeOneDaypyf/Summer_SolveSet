#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<long long> G[N];

void init()
{
    for(int i = 0;i < N;i ++)
        G[i].clear();
}

long long get_dis(pair<int,int> a,pair<int,int> b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        init();
        vector<pair<int,int> > p;
        for(int i = 0;i < n;i ++)
        {
            int x,y;
            cin >> x >> y;
            p.push_back(make_pair(x,y));
        }
        long long ans = 0;
        for(int i = 0;i < n;i ++)
        {
            for(int j = 0;j < n;j ++)
            {
                if(i == j)
                    continue;
                G[i].push_back(get_dis(p[i],p[j]));
            }
        }
        for(int i = 0;i < n;i ++)
        {
            sort(G[i].begin(),G[i].end());
            int cnt = 1;
            for(int j = 1;j < G[i].size();j ++)
            {
                if(G[i][j] == G[i][j - 1])
                    cnt ++;
                else
                {
                    ans += 1LL * (cnt - 1) * cnt;
                    cnt = 1;
                }
            }
            ans += 1LL * (cnt - 1) * cnt;
        }
        if(!ans)
            cout << "WA" << endl;
        else 
            cout << ans << endl;
    }
}