#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<int> G[N];
int vis[N];
int sz[N];
int root[2];
int max_len;

void init()
{
    memset(vis,0,sizeof(vis));
    memset(sz,0,sizeof(sz));
    for(int i = 0;i < N;i ++)
        G[i].clear();
}

void dfs(int u,int fa,int flag,int d)
{
    if(d >= max_len)
        root[flag] = u, max_len = d;
    vis[u] ^= flag;
    if(flag)
        sz[u] = 1;
    for(auto v : G[u])
    {
        if(v == fa)
            continue;
        dfs(v,u,flag,d + 1);
        if(flag)
            sz[u] += sz[v];
    }
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        init();
        for(int i = 0;i < m;i ++)
        {
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans = 0;
        int cnt = 0;
        for(int i = 1;i <= n;i ++) 
        {
            if(!vis[i])
            {
                max_len = 0;
                cnt ++;
                dfs(i,i,1,0);
                dfs(root[1],root[1],0,0);
                ans += (sz[i] - 1) * 2 - max_len;
            }
        }
        if(cnt == 1)
            cout << 0 << " " << m * 2 << endl;
        else
            cout << cnt << " " << ans << endl;
    }
}