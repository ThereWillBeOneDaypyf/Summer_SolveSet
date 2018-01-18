#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<sstream>
#include<stack>
#include<functional>
#include<cctype>
using namespace std;
typedef long long ll;

//thanks to pyf ...
//thanks to qhl ...

#define N 10000
#define INF 0x3f3f3f3f


struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f)
        : from(u), to(v), cap(c), flow(f) {}
};
struct Dinic
{
    int n, m, s, t;
    vector<Edge>edges;
    vector<int>G[N];
    bool vis[N];
    bool cut[N];
    int d[N];
    int cur[N];
    void add_undiredge(int u, int v, int cap)
    {
        edges.push_back(Edge(u, v, cap, 0));
        edges.push_back(Edge(v, u, cap, 0));
        int m = edges.size();
        G[u].push_back(m - 2);
        G[v].push_back(m - 1);
    }
    void add_diredge(int u, int v, int cap)
    {
        edges.push_back(Edge(u, v, cap, 0));
        edges.push_back(Edge(v, u, 0, 0));
        int m = edges.size();
        G[u].push_back(m - 2);
        G[v].push_back(m - 1);
    }
    bool bfs()
    {
        memset(vis, 0, sizeof(vis));
        queue<int>q;
        q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int dfs(int x, int a)
    {
        if (x == t || a == 0)
            return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i++)
        {
            Edge &e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (!a) break;
            }
        }
        return flow;
    }
    int Maxflow(int s, int t)
    {
        this -> s = s;
        this -> t = t;
        int flow = 0;
        memset(cut, 0, sizeof(cut));
        while (bfs())
        {
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, INF);
        }
        return flow;
    }
    void get_cut()
    {
        this -> s = s;
        this -> t = t;
        queue<int>qq;
        qq.push(s);
        cut[s] = 1;
        memset(cur, 0, sizeof(cur));
        while (!qq.empty())
        {
            int u = qq.front();
            qq.pop();
            for (int &i = cur[u]; i < G[u].size(); i++)
            {
                Edge &e = edges[G[u][i]];
                if (e.flow < e.cap && !cut[e.to])
                {
                    qq.push(e.to);
                    cut[e.to] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (cut[i])
            {
                for (int j = 0; j < G[i].size(); j++)
                {
                    Edge &e = edges[G[i][j]];
                    if (e.flow == e.cap && e.cap > 0 && !cut[e.to])
                    {
                        printf("%d %d\n", e.from, e.to);
                    }
                }
            }
        }
    }
};

int main()
{
    int T;
    int ka = 0;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> m >> n;
        Dinic ans;
        for (int i = 0; i < m; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            ans.add_diredge(u, v, c);
        }
        cout << "Case " << ++ ka << ": " << ans.Maxflow(1, n) << endl;
    }
}