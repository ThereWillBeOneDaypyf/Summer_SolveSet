#include<bits/stdc++.h>
using namespace std;

constexpr double INF = 1e18;

double getDis(int x,int y,const vector<pair<double,double> > &v)
{
    return sqrt((v[x].first - v[y].first) * (v[x].first - v[y].first) + 
        (v[x].second - v[y].second) * (v[x].second - v[y].second));
}

double dfs(int l,int r,const vector<pair<double,double> > &v)
{
    if(l == r)
        return INF;
    else if(l == r - 1)
        return getDis(l,r,v);
    int mid = (l + r) / 2;
    double ans = min(dfs(l,mid,v),dfs(mid + 1,r,v));
    vector<int> res;
    for(int i = l;i <= r;i ++)
        if(abs(v[i].first - v[mid].first) < ans)
            res.emplace_back(i);
    sort(res.begin(),res.end(),[&v](const int x,const int y){
        return v[x].second < v[y].second;
    });
    for(int i = 0;i < res.size();i ++)
    {
        for(int j = i + 1;j < res.size() && abs(v[res[i]].second - v[res[j]].second) < ans;j ++)
        {
            ans = min(ans,getDis(res[i],res[j],v));
        }
    }
    return ans;
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        if(n == 0)
            break;
        vector<pair<double,double> > v;
        for(int i = 0;i < n;i ++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            v.emplace_back(make_pair(x,y));
        }
        sort(v.begin(),v.end());
        printf("%.2lf\n",dfs(0,(int)v.size() - 1, v) / 2);
    }
}
