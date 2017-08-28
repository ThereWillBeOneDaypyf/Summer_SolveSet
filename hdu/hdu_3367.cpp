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