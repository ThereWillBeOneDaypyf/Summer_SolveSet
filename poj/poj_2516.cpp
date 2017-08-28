#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int MAXN = 500;
const int MAXM = 100000;
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
int Map[100][100][100];
int a[100][100], b[100][100];
int sum[100];
int main()
{
    ios :: sync_with_stdio(false);
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) == 3)
    {
        if (n == 0 && m == 0 && k == 0)
            break;
        memset(sum, 0, sizeof(sum));
        int s = 0;
        int t = n + m + 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++)
            {
                scanf("%d", &a[i][j]);
                sum[j] += a[i][j];
            }
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= k; j++)
                scanf("%d", &b[i][j]);
        for (int z = 1; z <= k; z++)
            for (int x = 1; x <= n; x ++)
                for (int y = 1; y <= m; y++)
                    scanf("%d", &Map[x][y][z]);
        int ans = 0;
        int flag = 1;
        for (int z = 1; z <= k; z++)
        {
            init(t + 1);
            int cost = 0;
            for (int i = 1; i <= n; i++)
                add_edge(m + i, t , a[i][z], 0);
            for (int i = 1; i <= m; i++)
                add_edge(s, i, b[i][z], 0);
            for (int i = 1; i <= m; i++)
                for (int j = 1; j <= n; j++)
                    add_edge(i, j + m, 3, Map[j][i][z]);
            if (minCostMaxflow(s, t, cost) != sum[z])
            {
                flag = 0;
                break;
            }
            else
                ans += cost;
        }
        if (!flag)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}