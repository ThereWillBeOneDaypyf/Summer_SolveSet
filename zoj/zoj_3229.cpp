//By kuangbin
//只能求一次最大流
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
// #pragma comment(linker, "/STACK:1024000000,1024000000")
const int MAXN = 2000;
const int MAXM = 400 * 1100; //注意边的数目，因为连边是连两条/经常re
const int INF = 0x3f3f3f3f;
using namespace std;
int n,s,t,N;//输入的顶点数，源点，汇点，总顶点数
struct Edge
{
    int to, next, cap, flow;
} edge[MAXM << 1];
int head[MAXN], tot, gap[MAXN], d[MAXN], cur[MAXN], que[MAXN], p[MAXN];
void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}
void add_undiredge(int u, int v, int c)
{
    edge[tot].to = v;
    edge[tot].cap = c;
    edge[tot].flow = 0;
    edge[tot].next = head[u];
    head[u] = tot++;
    edge[tot].to = u;
    edge[tot].cap = c;
    edge[tot].flow = 0;
    edge[tot].next = head[v];
    head[v] = tot++;
}
void add_diredge(int u, int v, int c)
{
    edge[tot].to = v;
    edge[tot].cap = c;
    edge[tot].flow = 0;
    edge[tot].next = head[u];
    head[u] = tot++;
    edge[tot].to = u;
    edge[tot].cap = 0;
    edge[tot].flow = 0;
    edge[tot].next = head[v];
    head[v] = tot++;
}
void BFS(int source, int sink)
{
    memset(d, -1, sizeof(d)); //clr(d,-1);
    memset(gap, 0, sizeof(gap)); //clr(gap,0);
    gap[0] = 1;
    int front = 0, rear = 0;
    d[sink] = 0;
    que[rear++] = sink;
    while (front != rear)
    {
        int u = que[front++];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (d[v] != -1) continue;
            que[rear++] = v;
            d[v] = d[u] + 1;
            gap[d[v]]++;
        }
    }
}
int isap(int source, int sink, int N)
{
    BFS(source, sink);
    memcpy(cur, head, sizeof(head));
    int top = 0, x = source, flow = 0;
    while (d[source] < N)
    {
        if (x == sink)
        {
            int Min = INF, inser;
            for (int i = 0; i < top; ++i)
            {
                if (Min > edge[p[i]].cap - edge[p[i]].flow)
                {
                    Min = edge[p[i]].cap - edge[p[i]].flow;
                    inser = i;
                }
            }
            for (int i = 0; i < top; ++i)
            {
                edge[p[i]].flow += Min;
                edge[p[i] ^ 1].flow -= Min;
            }
            flow += Min;
            top = inser;
            x = edge[p[top] ^ 1].to;
            continue;
        }
        int ok = 0;
        for (int i = cur[x]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (edge[i].cap > edge[i].flow && d[v] + 1 == d[x])
            {
                ok = 1;
                cur[x] = i;
                p[top++] = i;
                x = edge[i].to;
                break;
            }
        }
        if (!ok)
        {
            int Min = N;
            for (int i = head[x]; i != -1; i = edge[i].next)
            {
                if (edge[i].cap > edge[i].flow && d[edge[i].to] < Min)
                {
                    Min = d[edge[i].to];
                    cur[x] = i;
                }
            }
            if (--gap[d[x]] == 0) break;
            gap[d[x] = Min + 1]++;
            if (x != source) x = edge[p[--top] ^ 1].to;
        }
    }
    return flow;
}
// #include<iostream>
// #include<cstdio>
// #include<cstring>
// #include<cmath>
// #include<algorithm>
// #include<string>
// #include<vector>
// #include<set>
// #include<queue>
// #include<map>
// #include<sstream>
// #include<stack>
// #include<functional>
// #include<cctype>
// using namespace std;
// typedef long long ll;

// //thanks to pyf ...
// //thanks to qhl ...

// #define N 10000
// #define INF 0x3f3f3f3f


// struct Edge
// {
//     int from, to, cap, flow;
//     Edge(int u, int v, int c, int f)
//         : from(u), to(v), cap(c), flow(f) {}
// };
// struct Dinic
// {
//     int n, m, s, t;
//     vector<Edge>edges;
//     vector<int>G[N];
//     bool vis[N];
//     bool cut[N];
//     int d[N];
//     int cur[N];
//     void add_undiredge(int u, int v, int cap)
//     {
//         edges.push_back(Edge(u, v, cap, 0));
//         edges.push_back(Edge(v, u, cap, 0));
//         int m = edges.size();
//         G[u].push_back(m - 2);
//         G[v].push_back(m - 1);
//     }
//     void add_diredge(int u, int v, int cap)
//     {
//         edges.push_back(Edge(u, v, cap, 0));
//         edges.push_back(Edge(v, u, 0, 0));
//         int m = edges.size();
//         G[u].push_back(m - 2);
//         G[v].push_back(m - 1);
//     }
//     bool bfs()
//     {
//         memset(vis, 0, sizeof(vis));
//         queue<int>q;
//         q.push(s);
//         d[s] = 0;
//         vis[s] = 1;
//         while (!q.empty())
//         {
//             int x = q.front();
//             q.pop();
//             for (int i = 0; i < G[x].size(); i++)
//             {
//                 Edge &e = edges[G[x][i]];
//                 if (!vis[e.to] && e.cap > e.flow)
//                 {
//                     vis[e.to] = 1;
//                     d[e.to] = d[x] + 1;
//                     q.push(e.to);
//                 }
//             }
//         }
//         return vis[t];
//     }
//     int dfs(int x, int a)
//     {
//         if (x == t || a == 0)
//             return a;
//         int flow = 0, f;
//         for (int &i = cur[x]; i < G[x].size(); i++)
//         {
//             Edge &e = edges[G[x][i]];
//             if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
//             {
//                 e.flow += f;
//                 edges[G[x][i] ^ 1].flow -= f;
//                 flow += f;
//                 a -= f;
//                 if (!a) break;
//             }
//         }
//         return flow;
//     }
//     int Maxflow(int s, int t)
//     {
//         this -> s = s;
//         this -> t = t;
//         int flow = 0;
//         memset(cut, 0, sizeof(cut));
//         while (bfs())
//         {
//             memset(cur, 0, sizeof(cur));
//             flow += dfs(s, INF);
//         }
//         return flow;
//     }
//     void get_cut()
//     {
//         this -> s = s;
//         this -> t = t;
//         queue<int>qq;
//         qq.push(s);
//         cut[s] = 1;
//         memset(cur, 0, sizeof(cur));
//         while (!qq.empty())
//         {
//             int u = qq.front();
//             qq.pop();
//             for (int &i = cur[u]; i < G[u].size(); i++)
//             {
//                 Edge &e = edges[G[u][i]];
//                 if (e.flow < e.cap && !cut[e.to])
//                 {
//                     qq.push(e.to);
//                     cut[e.to] = 1;
//                 }
//             }
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             if (cut[i])
//             {
//                 for (int j = 0; j < G[i].size(); j++)
//                 {
//                     Edge &e = edges[G[i][j]];
//                     if (e.flow == e.cap && e.cap > 0 && !cut[e.to])
//                     {
//                         printf("%d %d\n", e.from, e.to);
//                     }
//                 }
//             }
//         }
//     }
// };

int g[MAXN];
int dif[MAXN];
int low[400][1100];
int eid[400][1100];
int main()
{
  int n,m;
  while(scanf("%d%d",&n,&m) == 2)
  {
    init();
    memset(dif,0,sizeof(dif));
    memset(low,0,sizeof(low));
    memset(eid,0,sizeof(eid));
    int s = 0, t = n + m + 1;
    int x = t + 1, y = t + 2;
    // ans.init(y + 1);
    // 1 - n day  n + 1 - m girls
    for(int i = 1;i <= m;i ++)
    {
      scanf("%d",&g[i]);
      // ans.add_diredge(n + i,t,INF - g[i]);
      add_diredge(n + i,t,INF - g[i]);
      dif[t] += g[i];
      dif[n + i] -= g[i];
    }
    for(int i = 1;i <= n;i ++)
    {
      int c,dd;
      scanf("%d%d",&c,&dd);
      add_diredge(s,i,dd);
      // ans.add_diredge(s,i,dd);
      for(int j = 0;j < c;j ++)
      {
        int id,l,r;
        scanf("%d%d%d",&id,&l,&r);
        // ans.add_diredge(i,id + 1 + n,r - l);
        add_diredge(i,id + 1 + n,r - l);
        dif[id + 1 + n] += l;
        dif[i] -= l;
        eid[i][id + 1] =  (tot - 1) ^ 1;
        // eid[i][id + 1] = ans.edges.size() - 2;
        low[i][id + 1] = l;
      }
    }
    int sum = 0;
    for(int i = 1;i <= t;i ++)
    {
      if(dif[i] > 0)
      {
        // ans.add_diredge(x,i,dif[i]);
        add_diredge(x,i,dif[i]);
        sum += dif[i];
      }
      if(dif[i] < 0)
      {
        // ans.add_diredge(i,y,-dif[i]);
        add_diredge(i,y,-dif[i]);
      }
    }
    // ans.add_diredge(t,s,INF);
    add_diredge(t,s,INF);
    int res = isap(x,y,y + 10);
    // int res = ans.Maxflow(x,y);
    if(res == sum)
    {
      res = isap(s,t,t + 10);
      // res = ans.Maxflow(s,t);
      printf("%d\n",res);
      for(int i = 1;i <= n;i ++)
      {
        for(int j = 1;j <= m;j ++)
        {
          if(eid[i][j])
            printf("%d\n",edge[eid[i][j]].flow + low[i][j]);
        }
      }
    }
    else printf("-1\n");
    printf("\n");
  }
  return 0;
}