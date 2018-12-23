// #include <cstdio>
// #include <cstring>
// #include <queue>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define INF (1 << 30)
// #define MAXN 222
// #define MAXM 222 * 444

// struct Edge
// {
//   int v, cap, flow, next;
// } edge[MAXM];
// int vs, vt, NE, NV;
// int head[MAXN];

// void addEdge(int u, int v, int cap)
// {
//   edge[NE].v = v;
//   edge[NE].cap = cap;
//   edge[NE].flow = 0;
//   edge[NE].next = head[u];
//   head[u] = NE++;
//   edge[NE].v = u;
//   edge[NE].cap = 0;
//   edge[NE].flow = 0;
//   edge[NE].next = head[v];
//   head[v] = NE++;
// }

// int level[MAXN];
// int gap[MAXN];
// void bfs()
// {
//   memset(level, -1, sizeof(level));
//   memset(gap, 0, sizeof(gap));
//   level[vt] = 0;
//   gap[level[vt]]++;
//   queue<int> que;
//   que.push(vt);
//   while (!que.empty())
//   {
//     int u = que.front();
//     que.pop();
//     for (int i = head[u]; i != -1; i = edge[i].next)
//     {
//       int v = edge[i].v;
//       if (level[v] != -1)
//         continue;
//       level[v] = level[u] + 1;
//       gap[level[v]]++;
//       que.push(v);
//     }
//   }
// }

// int pre[MAXN];
// int cur[MAXN];
// int ISAP()
// {
//   bfs();
//   memset(pre, -1, sizeof(pre));
//   memcpy(cur, head, sizeof(head));
//   int u = pre[vs] = vs, flow = 0, aug = INF;
//   gap[0] = NV;
//   while (level[vs] < NV)
//   {
//     bool flag = false;
//     for (int &i = cur[u]; i != -1; i = edge[i].next)
//     {
//       int v = edge[i].v;
//       if (edge[i].cap != edge[i].flow && level[u] == level[v] + 1)
//       {
//         flag = true;
//         pre[v] = u;
//         u = v;
//         //aug=(aug==-1?edge[i].cap:min(aug,edge[i].cap));
//         aug = min(aug, edge[i].cap - edge[i].flow);
//         if (v == vt)
//         {
//           flow += aug;
//           for (u = pre[v]; v != vs; v = u, u = pre[u])
//           {
//             edge[cur[u]].flow += aug;
//             edge[cur[u] ^ 1].flow -= aug;
//           }
//           //aug=-1;
//           aug = INF;
//         }
//         break;
//       }
//     }
//     if (flag)
//       continue;
//     int minlevel = NV;
//     for (int i = head[u]; i != -1; i = edge[i].next)
//     {
//       int v = edge[i].v;
//       if (edge[i].cap != edge[i].flow && level[v] < minlevel)
//       {
//         minlevel = level[v];
//         cur[u] = i;
//       }
//     }
//     if (--gap[level[u]] == 0)
//       break;
//     level[u] = minlevel + 1;
//     gap[level[u]]++;
//     u = pre[u];
//   }
//   return flow;
// }

// int low[MAXM];
// int id[MAXM];
// int ret[MAXN];

// // int main(){
// //     int t,n,m,a,b,c;
// //     scanf("%d",&t);
// //     while(t--){
// //         scanf("%d%d",&n,&m);
// //         memset(ret,0,sizeof(ret));
// //         vs=0; vt=n+1; NV=vt+1; NE=0;
// //         memset(head,-1,sizeof(head));
// //         for(int i=0; i<m; ++i){
// //             scanf("%d%d%d%d",&a,&b,low+i,&c);
// //             addEdge(a,b,c-low[i]);
// //             ret[b]+=low[i];
// //             ret[a]-=low[i];
// //         }
// //         int tot=0;
// //         for(int i=1; i<=n; ++i){
// //             if(ret[i]<0) addEdge(i,vt,-ret[i]);
// //             else addEdge(vs,i,ret[i]),tot+=ret[i];
// //         }
// //         if(ISAP()!=tot) puts("NO");
// //         else{
// //             puts("YES");
// //             for(int i=0; i<m; ++i){
// //                 printf("%d\n",edge[i<<1].flow+low[i]);
// //             }
// //         }
// //         putchar('\n');
// //     }
// //     return 0;
// // }

// int main()
// {
//   int T;
//   scanf("%d", &T);
//   int n, m;
//   while (T--)
//   {
//     scanf("%d%d", &n, &m);
//     memset(ret, 0, sizeof(ret));
//     vs = 0;
//     vt = n + 1;
//     NV = vt + 1;
//     NE = 0;
//     memset(head, -1, sizeof(head));
//     for (int i = 0; i < m; ++i)
//     {
//       int a,b,c;
//       scanf("%d%d%d%d", &a, &b, low + i, &c);
//       addEdge(a, b, c - low[i]);
//       ret[b] += low[i];
//       ret[a] -= low[i];
//       id[i] = ((NE - 1) ^ 1);
//       // id[i] = (i << 1);
//       // cout << id[i] << " " << (i << 1) << endl;
//     }
//     // for (int i = 0; i < m; i++)
//     // {
//     //   int u, v, up;
//     //   scanf("%d%d%d%d", &u, &v, &low[i], &up);
//     //   addEdge(u, v, up - low[i]);
//     //   ret[v] += low[i];
//     //   ret[u] -= low[i];
//     //   // ret[u] += low[i];
//     //   // ret[v] -= low[i];
//     //   id[i] = (NE - 1) ^ 1;
//     //   // cout << id[i] << endl;
//     // }
//     int sum = 0;
//     // for (int i = 1; i <= n; ++i)
//     // {
//     //   if (ret[i] < 0)
//     //     addEdge(i, vt, -ret[i]);
//     //   else
//     //     addEdge(vs, i, ret[i]), sum += ret[i];
//     // }
//     for (int i = 1; i <= n; i++)
//     {
//       if (ret[i] > 0)
//       {
//         sum += ret[i];
//         addEdge(vs, i, ret[i]);
//       }
//       else if (ret[i] < 0)
//         addEdge(i, vt, -ret[i]);
//       // if(ret[i] < 0)
//       //   addEdge(vs,i,-ret[i]);
//       // else addEdge(i,vt,ret[i]),sum+= ret[i];
//     }
//     // if (ISAP() != sum)
//     //   puts("NO");
//     // else
//     // {
//     //   puts("YES");
//     //   for (int i = 0; i < m; ++i)
//     //   {
//     //     printf("%d\n", edge[i << 1].flow + low[i]);
//     //   }
//     // }
//     // putchar('\n');
//     int res = ISAP();
//     if (res == sum)
//     {
//       printf("YES\n");
//       for (int i = 0; i < m; i++)
//       {
//         printf("%d\n", edge[id[i]].flow + low[i]);
//       }
//     }
//     else
//       printf("NO\n");
//     puts("");
//   }
//   return 0;
// }

//By kuangbin
//只能求一次最大流
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
// #pragma comment(linker, "/STACK:1024000000,1024000000")
const int MAXN = 2e2 + 7;
const int MAXM = 222 * 444; //注意边的数目，因为连边是连两条/经常re
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
  edge[tot].flow = c;
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

int ret[N];
int low[MAXM];
int up[MAXM];
int id[222 * 444];

int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    init();
    memset(ret,0,sizeof(ret));
    int s = 0, t = n + 1;
    for(int i = 0;i < m;i ++)
    {
      int u,v;
      scanf("%d%d%d%d",&u,&v,&low[i],&up[i]);
      add_diredge(u,v,up[i] - low[i]);
      ret[v] += low[i];
      ret[u] -= low[i];
      id[i] = ((tot - 1) ^ 1);
    }
    int sum = 0;
    for(int i = 1;i <= n;i ++)
    {
      if(ret[i] > 0)
      {
        add_diredge(s,i,ret[i]);
        sum += ret[i];
      }
      else
      {
        add_diredge(i,t,-ret[i]);
      }
    }
    int res = isap(s,t,n + 2);
    if(res == sum)
    {
      printf("YES\n");
      for(int i = 0;i < m;i ++)
      {
        printf("%d\n",low[i] + edge[id[i]].flow);
      }
    }
    else
    {
      printf("NO\n");
    }
    printf("\n");
    // printf("\n");
  }
}