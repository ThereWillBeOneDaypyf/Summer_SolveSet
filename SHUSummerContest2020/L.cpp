#include <bits/stdc++.h>
// const int MAXN = 1e3 + 1e2 + 7;
// const int MAXM = 2e5 + 7; //注意边的数目，因为连边是连两条/经常re
// const long long INF = 1e18;
using namespace std;
//int n,s,t,N;//输入的顶点数，源点，汇点，总顶点数
// struct Edge
// {
//     int to, next;
//     long long cap, flow;
// } edge[MAXM << 1];
// int head[MAXN], tot, gap[MAXN], d[MAXN], cur[MAXN], que[MAXN], p[MAXN];
// void init()
// {
//     tot = 0;
//     memset(head, -1, sizeof(head));
// }
// void add_undiredge(int u, int v, long long c)
// {
//     edge[tot].to = v;
//     edge[tot].cap = c;
//     edge[tot].flow = 0;
//     edge[tot].next = head[u];
//     head[u] = tot++;
//     edge[tot].to = u;
//     edge[tot].cap = c;
//     edge[tot].flow = 0;
//     edge[tot].next = head[v];
//     head[v] = tot++;
// }
// void add_diredge(int u, int v, int c)
// {
//     edge[tot].to = v;
//     edge[tot].cap = c;
//     edge[tot].flow = 0;
//     edge[tot].next = head[u];
//     head[u] = tot++;
//     edge[tot].to = u;
//     edge[tot].cap = 0;
//     edge[tot].flow = 0;
//     edge[tot].next = head[v];
//     head[v] = tot++;
// }
// void BFS(int source, int sink)
// {
//     memset(d, -1, sizeof(d)); //clr(d,-1);
//     memset(gap, 0, sizeof(gap)); //clr(gap,0);
//     gap[0] = 1;
//     int front = 0, rear = 0;
//     d[sink] = 0;
//     que[rear++] = sink;
//     while (front != rear)
//     {
//         int u = que[front++];
//         for (int i = head[u]; i != -1; i = edge[i].next)
//         {
//             int v = edge[i].to;
//             if (d[v] != -1) continue;
//             que[rear++] = v;
//             d[v] = d[u] + 1;
//             gap[d[v]]++;
//         }
//     }
// }
// void debug(int N)
// {
//     for(int i = 0; i <= N; i++)
//     {
//         cout << "head: " << i << endl;
//         for(int j = head[i]; j != -1; j = edge[j].next)
//         {
//             cout << "-----> " << edge[j].to << " ";
//         }
//         cout << endl;
//     }
// }
// long long isap(int source, int sink, int N)
// {
//     BFS(source, sink);
//     memcpy(cur, head, sizeof(head));
//     // debug(N);
//     int top = 0, x = source;
//     long long flow = 0;
//     while (d[source] < N)
//     {
//         if (x == sink)
//         {
//             long long Min = INF, inser;
//             for (int i = 0; i < top; ++i)
//             {
//                 if (Min > edge[p[i]].cap - edge[p[i]].flow)
//                 {
//                     Min = edge[p[i]].cap - edge[p[i]].flow;
//                     inser = i;
//                 }
//             }
//             for (int i = 0; i < top; ++i)
//             {
//                 edge[p[i]].flow += Min;
//                 edge[p[i] ^ 1].flow -= Min;
//             }
//             flow += Min;
//             top = inser;
//             x = edge[p[top] ^ 1].to;
//             continue;
//         }
//         int ok = 0;
//         for (int i = cur[x]; i != -1; i = edge[i].next)
//         {
//             int v = edge[i].to;
//             if (edge[i].cap > edge[i].flow && d[v] + 1 == d[x])
//             {
//                 ok = 1;
//                 cur[x] = i;
//                 p[top++] = i;
//                 x = edge[i].to;
//                 break;
//             }
//         }
//         if (!ok)
//         {
//             int Min = N;
//             for (int i = head[x]; i != -1; i = edge[i].next)
//             {
//                 if (edge[i].cap > edge[i].flow && d[edge[i].to] < Min)
//                 {
//                     Min = d[edge[i].to];
//                     cur[x] = i;
//                 }
//             }
//             if (--gap[d[x]] == 0) break;
//             gap[d[x] = Min + 1]++;
//             if (x != source) x = edge[p[--top] ^ 1].to;
//         }
//     }
//     return flow;
// }
#define N 2000
// #define INF 1e18


struct Edge
{
    int from, to;
    long long cap, flow;
    Edge(int u, int v, long long c, long long f)
        : from(u), to(v), cap(c), flow(f) {}
};
struct Dinic1
{
    int n, m, s, t;
    vector<Edge>edges;
    vector<int>G[N];
    bool vis[N];
    bool cut[N];
    int d[N];
    int cur[N];
    void add_undiredge(int u, int v, long long cap)
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
    long long dfs(int x, long long a)
    {
        if (x == t || a == 0)
            return a;
        long long flow = 0, f;
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
    long long Maxflow(int s, int t)
    {
        this -> s = s;
        this -> t = t;
        long long flow = 0;
        memset(cut, 0, sizeof(cut));
        while (bfs())
        {
            memset(cur, 0, sizeof(cur));
            // flow += dfs(s, INF);
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

#include <bits/stdc++.h>

template <typename T, T INF>
struct Dinic {
    struct Edge {
        int from, to;
        T cap, flow;
        Edge(int u, int v, T c, T f) : from(u), to(v), cap(c), flow(f) {}
    };
    int n, m, s, t;
    std::vector<Edge> edges;
    std::vector<std::vector<int>> G;
    std::vector<bool> vis;
    std::vector<int> d;
    std::vector<int> cur;
    Dinic(int n) : n(n), G(n), vis(n), d(n), cur(n) {}
    void AddEdge(int from, int to, T cap) {
        edges.emplace_back(from, to, cap, 0);
        edges.emplace_back(to, from, 0, 0);
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool BFS() {
        std::fill(vis.begin(), vis.end(), false);
        std::fill(d.begin(), d.end(), 0);
        std::queue<int> q;
        q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if (!vis[e.to] and e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    T DFS(int x, T a) {
        if (x == t || a == 0) return a;
        T flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++) {
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] and
                (f = DFS(e.to, std::min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }
    T Maxflow(int s, int t) {
        this->s = s, this->t = t;
        T flow = 0;
        while (BFS()) {
            std::fill(cur.begin(), cur.end(), 0);
            flow += DFS(s, INF);
        }
        return flow;
    }
};

int b[N];

int main()
{
    int n;
    long long e;
    while(scanf("%d%lld", &n, &e) == 2)
    {
        vector<vector<int> > v = vector<vector<int> > (8);
        int sum = 0;
        int target = 0;
        for(int i = 1; i <= n; i ++)
        {
            int c, m;
            scanf("%d%d", &b[i], &m);
            sum += b[i];
            for(int j = 0; j < m; j ++)
            {
                int d;
                scanf("%d", &d);
                v[d].push_back(i);
            }
        }
        long long l = 1, r = 14LL * sum;
        int s = 0;
        int t = n + 7 + 1;
        long long ans = r + 1;
        while(l <= r)
        {
            const long long x = 1e18;
            Dinic<long long, x> d(t + 1);
            long long mid = (l + r) / 2;
            long long week = mid / 7;
            for(int i = 1; i <= 7; i ++)
            {
                long long days = week;
                if (week * 7 + i <= mid)
                    days ++;
                // d.add_undiredge(s, i, days * e);
                d.AddEdge(s, i, days * e);
                for(int j = 0; j < v[i].size();j ++)
                {
                    int id = v[i][j] + 7;
                    // d.add_undiredge(i, id, INF);
                    d.AddEdge(i, id, x);
                }
            }
            for(int i = 1; i <= n; i ++)
            {
                int id = i + 7;
                // d.add_undiredge(id, t, b[i]);
                d.AddEdge(id, t, b[i]);
            }
            long long cur = d.Maxflow(s, t);
            if(cur == sum) 
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else 
            {
                l = mid + 1;
            }
        }
        printf("%lld\n", ans);
    }
}

