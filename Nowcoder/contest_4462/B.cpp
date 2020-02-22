#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<int> G[N];
long long a[N];
int root = 1;
long long m_max = 0;

void init() 
{
    root = 1;
    for(int i = 0;i < N; i ++)
    {
        G[i].clear();
    }
}

void dfs(int u,int fa, long long val)
{
    if(val >= m_max)
    {
        root = u;
        m_max = val;
    }
    for(auto v : G[u])
    {
        if(v == fa)
            continue;
        dfs(v, u, val + a[v]);
    }
}

int main()
{
    int n;
    while(cin >> n)
    {
        init();
        for(int i = 1; i <= n; i ++)
            cin >> a[i];
        for(int i = 1; i < n; i ++) 
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        m_max = a[root];
        dfs(root, root, a[root]);
        dfs(root, root, a[root]);
        cout << m_max << endl;
    }
}