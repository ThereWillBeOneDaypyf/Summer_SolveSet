#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int Map[1005][1005];
int head[N];
int tot = 0;
int dis[N];
void init()
{
    memset(Map, -1, sizeof(Map));
}
int n;
int vis[N];
int spfa()
{
    memset(dis, -1, sizeof(dis));
    dis[1] = 1e9;
    memset(vis, 0, sizeof(vis));
    queue<int>q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (Map[u][i] == -1)
                continue;
            int v = i;
            int d = Map[u][i];
            if (dis[v] == -1)
            {
                dis[v] = min(dis[u], d);
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
            else if (min(dis[u], d) > dis[v])
            {
                dis[v] = min(dis[u], d);
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return dis[n];
}
int main()
{
    int m;
    int T;
    scanf("%d", &T);
    int ka = 0;
    while (T--)
    {
        init();
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            Map[u][v] = max(Map[u][v], c);
            Map[v][u] = max(Map[v][u], c);
        }
        printf("Scenario #%d:\n%d\n\n", ++ka, spfa());
    }
}