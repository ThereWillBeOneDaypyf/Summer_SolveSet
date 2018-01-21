#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e3;

map<int,int> pri;
vector<pair<int,int> > G[N];
set<int> s[N];
int dp[N];
void dfs(int u,set<int> curs,long long cur)
{
    if(dp[u] > cur)
        s[u] = curs,dp[u] = cur;
    for(auto v : G[u])
    {
        set<int> temps(curs);
        if(!temps.count(v.second))
        {
            temps.insert(v.second);
            dfs(v.first,temps,cur + pri[v.second]);
        }
        else
            dfs(v.first,temps,cur);
    }
}
int main()
{
    int n,m,k,c;
    while(cin >> n >> m >> k >> c)
    {
        for(int i = 0;i < N;i++)
            G[i].clear(),s[i].clear();
        for(int i = 0;i < m;i++)
        {
            int x;
            int u,v;
            cin >> u >> v >> x;
            G[u].push_back(make_pair(v,x));
        }
        for(int i = 0;i < k;i++)
        {
            int id,p;
            cin >> id >> p;
            if(pri.count(id))
                pri[id] = min(pri[id],p);
            else
                pri[id] = p;
        }
        memset(dp,0x3f3f3f3f,sizeof(dp));
        dfs(1,s[0],0);
        cout << dp[c] << endl;
    }
}