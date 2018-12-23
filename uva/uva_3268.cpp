//By kuangbin
//只能求一次最大流
#include<bits/stdc++.h>
// #pragma comment(linker, "/STACK:1024000000,1024000000")
const int MAXN = 1e5 + 7;
const int MAXM = 2e6 + 7; //注意边的数目，因为连边是连两条/经常re
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


vector<int> G[MAXN];

void clr()
{
  for(int i = 0;i < MAXN;i ++)
    G[i].clear();
}

pair<int,vector<int> > parse(string& s,int id)
{
  bool name = true;
  vector<int> v;
  string cur_str = "";
  for(auto ele : s)
  {
    if(ele == ' ')
    {
      if(name)
      {
        name = false;
        cur_str.clear();
      }
      else
      {
        v.push_back(stoi(cur_str));
        cur_str.clear();
      }
    }
    else cur_str.push_back(ele);
  }
  if(!cur_str.empty())
    v.push_back(stoi(cur_str));
  return make_pair(id,v);
}

void build(int n,int m,int flow)
{
  init();
  int s = 0;
  int t = n + m + 1;
  for(int i = 1;i <= n;i ++)
  {
    add_diredge(s,i,1);
    for(auto ele : G[i])
    {
      add_diredge(i,ele + n,1);
    }
  }
  for(int i = 1;i <= m;i ++)
    add_diredge(i + n,t,flow);
}

int main()
{
  int n,m;
  ios :: sync_with_stdio(false);
  while(cin >> n >> m)
  {
    if(n == 0 && m == 0)
      break;
    clr();
    string s;
    getline(cin,s);
    for(int i = 1;i <= n;i ++)
    {
      getline(cin,s);
      auto res = parse(s,i);
      G[i] = res.second;
      for(auto& ele : G[i])
        ele ++;
    }
    int l = 0,r = n;
    int ans = n;
    // for(int i = 1;i <= n;i ++)
    // {
    //   cout << i << " -----> ";
    //   for(auto ele : G[i])
    //     cout << ele << " ";
    //   cout << endl;
    // }
    while(l <= r)
    {
      int mid = (l + r) / 2; 
      // cout << mid << endl;
      build(n,m,mid);
      int res = isap(0,n + m + 1,n + m + 2);
      if(res == n)
      {
        ans = min(mid,ans);
        r = mid - 1;
      }
      else l = mid + 1;
    }
    cout << ans << endl;
  }
}