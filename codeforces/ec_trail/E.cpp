//By kuangbin
//只能求一次最大流
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
const int MAXM = 1e6 + 7; //注意边的数目，因为连边是连两条/经常re
const int INF = 0x3f3f3f3f;
using namespace std;
//int n,s,t,N;//输入的顶点数，源点，汇点，总顶点数
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
  memset(d, -1, sizeof(d));    //clr(d,-1);
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
      if (d[v] != -1)
        continue;
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
      if (--gap[d[x]] == 0)
        break;
      gap[d[x] = Min + 1]++;
      if (x != source)
        x = edge[p[--top] ^ 1].to;
    }
  }
  return flow;
}

const int N = 1e3;

int a[N];

int main()
{
  ios :: sync_with_stdio(false);
  int n;
  while(cin >> n)
  {
    int s = 0,t = n + 1;
    init();
    int sum = 0;
    for(int i = 1;i <= n;i ++)
    {
      cin >> a[i];
      if(a[i] > 0)
      {
        sum += a[i];
        add_diredge(i,t,a[i]);
      }
      else if(a[i] < 0)
      {
        add_diredge(s,i,-a[i]);
      }
    }
    for(int i = 1;i <= n;i ++)
    {
      for(int j = i + i;j <= n;j += i)
      {
        add_diredge(i,j,INF);
      }
    }
    int res = isap(s,t,n + 2);
    cout << sum - res << endl;
  }
}