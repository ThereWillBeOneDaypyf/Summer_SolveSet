#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n,m;
vector<int> G[N];
int vis[N];
int flag = 0;
void init()
{
    for(int i = 0;i < N;i ++)
        G[i].clear();
    memset(vis,0,sizeof(vis));
}

void dfs(int u)
{
    vis[u] = 1;
    if(u == n)
        flag = 1;
    for(auto v : G[u])
    {
        if(vis[v])
            continue;
        dfs(v);
    }
}

int main()
{
    while(cin >> n >> m)
    {
        init();
        for(int i = 0;i < m;i ++)
        {
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
        }
        flag = 0;
        dfs(1);
        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } 
}