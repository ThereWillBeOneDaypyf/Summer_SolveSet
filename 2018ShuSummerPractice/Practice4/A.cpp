#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<int> G[N];

long long dp[N][510];
long long ans = 0;
int n,k;

void init()
{
    for(int i = 0;i < N;i ++)
        G[i].clear();
    memset(dp,0,sizeof(dp));
}

void dfs(int u,int fa)
{
    dp[u][0] = 1;
    for(auto v : G[u])
    {
        if(v == fa)
            continue;
        dfs(v,u);
        for(int i = 0;i <= k;i ++)
            ans += dp[u][i] * dp[v][k - i - 1];
        for(int i = 1;i <= k;i ++)
            dp[u][i] += dp[v][i - 1];
    }
}

int main()
{
    while(cin >> n >> k)
    {
        init();
        for(int i = 1;i < n;i ++)
        {
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ans = 0;
        dfs(1,1);
        cout << ans << endl;
    }
}