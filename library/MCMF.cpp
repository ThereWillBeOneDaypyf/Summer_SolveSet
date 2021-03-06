#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<functional>
using namespace std;
//需要初始化点数 init函数
#define N 1000
#define INF 100000000

struct Edge
{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int ca, int f, int co): from(u), to(v), cap(ca), flow(f), cost(co) {};
};

struct MCMF
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[N];
    int inq[N];//是否在队列中
    int d[N];//距离
    int p[N];//上一条弧
    int a[N];//可改进量

    void init(int n)//初始化
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }

    void add_edge(int from, int to, int cap, int cost) //加边
    {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        int m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool SPFA(int s, int t, int &flow, int &cost) //寻找最小费用的增广路，使用引用同时修改原flow,cost
    {
        for (int i = 0; i < n; i++)
            d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;
        queue<int> Q;
        Q.push(s);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            inq[u]--;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) //满足可增广且可变短
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to])
                    {
                        inq[e.to]++;
                        Q.push(e.to);
                    }
                }
            }
        }
        if (d[t] == INF) return false; //汇点不可达则退出
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while (u != s) //更新正向边和反向边
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    int MincotMaxflow(int s, int t)
    {
        int flow = 0, cost = 0;
        while (SPFA(s, t, flow, cost));
        return cost;
    }
};

vector<pair<int, int> > home;
vector<pair<int, int> > people;
int dis(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int main()
{
    ios :: sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        MCMF ans;
        int s = 0;
        home.clear(), people.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char x;
                cin >> x;
                if (x == 'm')
                    people.push_back(make_pair(i, j));
                else if (x == 'H')
                    home.push_back(make_pair(i, j));
            }
        }
        int t = home.size() + people.size() + 1;
        ans.init(t + 1);
        for (int i = 0; i < home.size(); i++)
            ans.add_edge(i + people.size() + 1, t, 1, 0);
        for (int i = 0; i < people.size(); i++)
            ans.add_edge(s, i + 1, 1, 0);
        for (int i = 0; i < people.size(); i++)
            for (int j = 0; j < home.size(); j++)
                ans.add_edge(i + 1, j + people.size() + 1, 1, dis(people[i], home[j]));
        cout << ans.MincotMaxflow(s, t) << endl;
    }
    return 0;
}
/*
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAXN = 800000 + 1000;
const int MAXM = 4000000 + 1000;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to, next, cap, flow, cost;
} edge[MAXM];
int head[MAXN], tol;
int pre[MAXN], dis[MAXN];
bool vis[MAXN];
int N;//节点总个数，节点编号从0~N-1
void init(int n)
{
    N = n;
    tol = 0;
    memset(head, -1, sizeof(head));
}
void add_edge(int u, int v, int cap, int cost)
{
    edge[tol].to = v;
    edge[tol].cap = cap;
    edge[tol].cost = cost;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = 0;
    edge[tol].cost = -cost;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}
bool spfa(int s, int t)
{
    queue<int>q;
    for (int i = 0; i < N; i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (edge[i].cap > edge[i].flow &&
                    dis[v] > dis[u] + edge[i].cost)
            {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if (pre[t] == -1)return false;
    else return true;
}
//返回的是最大流，cost存的是最小费用
int minCostMaxflow(int s, int t, int &cost)
{
    int flow = 0;
    cost = 0;
    while (spfa(s, t))
    {
        int Min = INF;
        for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to])
        {
            if (Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to])
        {
            edge[i].flow += Min;
            edge[i ^ 1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}
int Map[700][700];
int xdir[2] = {0, 1};
int ydir[2] = {1, 0};
bool ok(int x, int y, int n)
{
    if (x < 1 || x > n || y < 1 || y > n)
        return false;
    return true;
}
int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &Map[i][j]);
        init(n * n * 2 + 2);
        int s = 0, t = n * n * 1;
        add_edge(s, 1, 2, Map[1][1]);
        add_edge(n * n * 2 , t, 2, Map[n][n]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((i == 1 && j == 1) || (i == n && j == n))
                    add_edge((i - 1) * n + j , (i - 1) * n + j + n * n, 2, - Map[i][j]);
                else
                    add_edge((i - 1) * n + j , (i - 1) * n + j + n * n , 1, -Map[i][j]);
                for (int k = 0; k < 2; k++)
                {
                    int tx = i + xdir[k];
                    int ty = j + ydir[k];
                    if (ok(tx, ty, n))
                    {
                        add_edge((i - 1) * n + j + n * n, (tx - 1) * n + ty, 1, 0);
                    }
                }
            }
        }
        int ans = 0;
        minCostMaxflow(s, t, ans);
        printf("%d\n", -ans + Map[1][1] + Map[n][n]);
    }
}
 */