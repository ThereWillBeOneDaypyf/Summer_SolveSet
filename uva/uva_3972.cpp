#include <bits/stdc++.h>
using namespace std;

//By kuangbin
//只能求一次最大流
// #pragma comment(linker, "/STACK:1024000000,1024000000")
const int MAXN = 2e2 + 7;
const int MAXM = 2e5 + 7; //注意边的数目，因为连边是连两条/经常re
const int INF = 0x3f3f3f3f;
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

struct Node
{
  int x,y;
  int p_cnt,dis_cnt;
};
vector<Node> v;
double D;
int n;
int sum = 0;

bool judge(int i,int j)
{
  if((v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y) <= D * D)
    return true;
  return false;
}

bool solve(int t)
{
  init();
  int s = 0;
  for(int i = 0;i < n;i ++)
  {
    if(i == t)
      continue;
    add_diredge(s,i + 1,v[i].p_cnt);
    add_diredge(i + 1,i + 1 + n,v[i].dis_cnt);
    for(int j = 0;j < n;j ++)
    {
      if(i == j)
        continue;
      if(judge(i,j))
      {
        add_diredge(i + 1 + n,j + 1,INF);
      }
    }
  }
  int res = isap(s,t + 1,n + n + 2);
  if(res == sum - v[t].p_cnt)
    return true;
  return false;
}

int main()
{
  ios :: sync_with_stdio(false);
  int T;
  cin >> T;
  while(T --)
  {
    v.clear();
    cin >> n >> D; 
    sum = 0;
    for(int i = 0;i < n;i ++)
    {
      int x,y,p_cnt,dis_cnt;
      cin >> x >> y >> p_cnt >> dis_cnt;
      sum += p_cnt;
      v.push_back({x,y,p_cnt,dis_cnt});
    }
    vector<int> ans;
    for(int i = 0;i < n;i ++)
    {
      if(solve(i))
        ans.push_back(i);
    }
    if(ans.empty())
      cout << -1 << endl;
    else 
    {
      for(int i = 0;i < ans.size();i ++)
      {
        if(i)
          cout << " ";
        cout << ans[i];
      }
      cout << endl;
    }
  }
}

/*
*/