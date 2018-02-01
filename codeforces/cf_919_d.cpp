#include<bits/stdc++.h>
using namespace std;

constexpr int N = 3e5 + 7;

int dp[N][26];
int vis[N];
vector<int> G[N];

void init()
{
    for(int i = 0;i < N;i ++)
        G[i].clear();
    memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));
}

bool judge(int u)
{
    if(vis[u] == -1)
        return false;
    if(vis[u])
        return true;
    vis[u] = -1;
    for(auto v : G[u])
        if(!judge(v))
            return false;
    vis[u] = 1;
    return true;
}

void dfs(int u,char *w)
{
    if(dp[u][0] != -1)
        return;
    for(int i = 0;i < 26;i ++) 
        dp[u][i] = 0;
    for(auto v : G[u])
    {
        dfs(v, w);
        for(int i = 0; i < 26; i++)
            dp[u][i] = max(dp[u][i], dp[v][i]);
    }
    dp[u][w[u - 1] - 'a'] ++;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        char w[N];
        scanf("%s",w);
        for(int i = 0;i < m;i ++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        int flag = 1;
        for(int i = 1;i <= n;i ++)
        {
            if(!vis[i])
                if(!judge(i))
                {
                    flag = 0;
                    break;
                }
        }
        if(!flag)
        {
            printf("-1\n");
            continue;
        }
        for(int i = 1;i <= n;i++)
            dfs(i,w);
        int ans = 0;
        for(int i = 1;i <= n;i ++)
            for(int j = 0;j < 26;j ++)
                ans = max(ans, dp[i][j]);
        printf("%d\n",ans);
    }
}