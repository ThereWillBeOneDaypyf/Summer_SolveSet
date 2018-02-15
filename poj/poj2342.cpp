#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N = 1e4;

vector<int> G[N];
int a[N];
int dp[N][2];
int deg[N];
void init()
{
    for(int i = 0;i < N;i++)
        G[i].clear();
    memset(deg,0,sizeof(deg));
}
void add_edge(int u,int v)
{
    G[u].push_back(v);
    deg[v] ++;
}
void dfs(int u,int fa)
{
    dp[u][0] = 0;
    for(int i = 0;i < G[u].size();i++)
    {
        int v = G[u][i];
        if(v == fa)
            continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1]);
    }
    dp[u][1] = 0;
    for(int i = 0;i < G[u].size();i++)
    {
        int v = G[u][i];
        if(v == fa)
            continue;
        dp[u][1] += dp[v][0];
    }
    dp[u][1] += a[u];
}
int main()
{
    ios :: sync_with_stdio(false);
    int n;
    while(cin >> n)
    {
        init();
        for(int i = 1;i <= n;i ++)
            cin >> a[i];
        int u,v;
        while(cin >> u >> v && u && v)
            add_edge(v,u);
        for(int i = 1;i <= n;i++)
            if(!deg[i])
            {
                dfs(i,i);
                cout << max(dp[i][0],dp[i][1]) << endl;
            }
    }
}