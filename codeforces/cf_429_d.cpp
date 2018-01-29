#include<bits/stdc++.h>
using namespace std;

constexpr long long INF = 1e18 + 7;

inline long long getDis(const pair<int, int> &x,
                                const pair<int, int> &y)
{
    return 1LL * (x.first - y.first) * (x.first - y.first) + 1LL * (x.second - y.second) * (x.second - y.second); 
}
long long dfs(int l,int r,const vector<pair<int,int> > &v)
{
    if(l == r)
        return INF;
    else if(l == r - 1)
        return getDis(v[l],v[r]);
    int mid = (l + r) / 2;
    long long ans = min(dfs(l, mid, v),dfs(mid + 1, r, v));
    vector<pair<int,int> > res;
    for(int i = l;i <= r;i ++)
        if(abs(v[i].first - v[mid].first) < ans)
            res.emplace_back(v[i]);
    sort(res.begin(),res.end(),[](const pair<int,int> a,
                const pair<int,int> b){
        return a.second < b.second;
    });
    for(int i = 0;i < res.size();i ++)
    {
        for(int j = i + 1;j < res.size() && j < i + 8 && abs(res[i].second - res[j].second) < ans;j ++)
        {
            ans = min(ans, getDis(res[i],res[j]));
        }
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        vector<int> v;
        v.assign(n + 1,0);
        for(int i = 1;i <= n;i ++)
            scanf("%d",&v[i]);
        vector<int> pre_sum;
        pre_sum.assign(n + 1,0);
        for(int i = 1;i <= n; i ++)
            pre_sum[i] = pre_sum[i - 1] + v[i];
        vector<pair<int,int> > solvev;
        for(int i = 1;i <= n;i ++)
            solvev.emplace_back(make_pair(i,pre_sum[i]));
        sort(solvev.begin(),solvev.end());
        printf("%lld\n",dfs(0, static_cast<int>(solvev.size()) - 1, solvev));
        //cout << dfs(0, static_cast<int> (solvev.size()) - 1, solvev) << endl;
    }
}