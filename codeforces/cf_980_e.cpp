#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int fa[N][21];
vector<int> G[N];
bool vis[N];
int dep[N];

void init()
{
    for(int i = 0;i < N;i ++)
        G[i].clear();
    memset(vis,0,sizeof(vis));
}

void dfs(int u,int f,int d)
{
    fa[u][0] = f;
    dep[u] = d;
    for(int i = 1;i <= 20;i ++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(auto v : G[u])
    {
        if(v == f)
            continue;
        dfs(v,u,d + 1);
    }
}

int go(int u)
{
    for(int i = 20;i >= 0;i --)
        if(!vis[fa[u][i]])
            u = fa[u][i];
    return u;
}

int main()
{
    //ios :: sync_with_stdio(false);
    int n,k;
    while(scanf("%d%d",&n,&k) == 2)
    {
        init();
        for(int i = 1;i < n;i ++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(n,n,0);
        k = n - k;
        vis[n] = 1;
        k --;
        for(int i = n - 1;i >= 1;i --)
        {
            int pre = go(i);
            if(dep[i] - dep[pre] + 1 > k)
                continue;
            int r = i;
            while(!vis[r])
            {
                vis[r] = 1;
                r = fa[r][0];
                k --;
            }
        }
        vector<int> anc;
        for(int i = 1;i <= n;i ++)
        {
            if(!vis[i])
                anc.push_back(i);
        }
        for(int i = 0;i < anc.size();i ++)
        {
            if(i)
                printf(" ");
            printf("%d",anc[i]);
        }
        printf("\n");
    }
}
