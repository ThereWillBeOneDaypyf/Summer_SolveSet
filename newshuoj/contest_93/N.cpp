#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

struct Trie
{
  int next[2];
  int val;
}t[N * 80];
int fa[N][20];

vector<int> G[N];
int root[N];
int dep[N];
int a[N];

int cnt = 0;

void init()
{
  for(int i = 0;i < N; i ++)
    G[i].clear();
  cnt = 0;
  memset(root,0,sizeof(root));
  memset(t,0,sizeof(t));
}

int new_node()
{
  cnt ++;
  for(int i = 0;i < 2;i ++)
    t[cnt].next[i] = 0;
  t[cnt].val = 0;
  return cnt;
}

void add_edge(int u,int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}

void cp(int x,int y)
{
  for(int i = 0;i < 2;i ++)
    t[x].next[i] = t[y].next[i];
  t[x].val = t[y].val;
}

void insert(int x,int y,int val)
{
  for(int i = 30;i >= 0;i --)
  {
    int tar;
    t[x].val ++;
    if((val & (1 << i)))
      tar = 1;
    else tar = 0;
    // cout << tar;
    t[x].next[tar] = new_node();
    cp(t[x].next[tar],t[y].next[tar]); 
    x = t[x].next[tar]; 
    y = t[y].next[tar];
  }
  // cout << endl;
  t[x].val ++;
}

void dfs(int u,int f,int d)
{
  fa[u][0] = f;
  dep[u] = d;
  for(int i = 1;i < 20;i ++)
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
  root[u] = new_node();
  cp(root[u],root[f]);
  insert(root[u],root[f],a[u]);
  for(auto v : G[u])
  {
    if(v == f)
      continue;
    dfs(v,u,d+1);
  }
}

pair<int,int> query(int x,int y,int val)
{
  int res = 0;
  int ans = 0;
  for(int i = 30;i >= 0;i --)
  {
    int tar;
    ans <<= 1;
    res <<= 1;
    if((val & (1 << i)))
      tar = 0;
    else tar = 1;
    if(t[t[y].next[tar]].val - t[t[x].next[tar]].val > 0)
    {
      ans |= 1;
      res += tar;
      // cout << tar;
      x = t[x].next[tar];
      y = t[y].next[tar];
    }
    else
    {
      res += (tar ^ 1);
      // cout << !tar;
      x = t[x].next[!tar];
      y = t[y].next[!tar];
    }
  }
  // cout << endl;
  return make_pair(ans,res);
}

int lca(int x,int y)
{
  // cout << x << " " << y << endl;
  if(dep[x] < dep[y])
    swap(x,y);
  for(int i = 19;i >= 0;i --)
    if(dep[fa[x][i]] >= dep[y])
      x = fa[x][i];
  if(x == y)
    return x;
  for(int i = 19;i >= 0;i --)
    if(fa[x][i] != fa[y][i])
      x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}

int go(int u,int v,int val)
{
  // cout << u << " " << v << endl;
  int anc = lca(u,v);
  // cout << "u v anc : " << u << " " << v << " " << anc << " " << fa[anc][0] << endl;
  pair<int,int> temp1 = query(root[fa[anc][0]],root[u],val);
  // cout << temp1.first << " " << temp1.second << endl;
  pair<int,int> temp2 = query(root[fa[anc][0]],root[v],val);
  // cout << temp2.first << " " << temp2.second << endl;
  if(temp1.first > temp2.first)
    return temp1.second;
  else return temp2.second;
}

int main()
{
  int T;
  // freopen("2.in","r",stdin);
  // freopen("my2.out","w",stdout);
  scanf("%d",&T);
  // printf("%d\n",T);
  while(T--)
  {
    int n,q;
    init();
    scanf("%d%d",&n,&q);
    // printf("%d %d\n",n,q);
    for(int i = 1;i <= n;i ++)
      scanf("%d",a + i);
    for(int i = 1;i < n;i ++) 
    {
      int u,v;
      scanf("%d%d",&u,&v);
      // printf("%d %d\n",u,v);
      add_edge(u,v);
    }
    dfs(1,0,0);
    // for(int i = 1;i <= n;i ++)
    //   cout << dep[i] << " ";
    // cout << endl;
    for(int i = 0;i < q;i ++)
    {
      int u,v,val;
      scanf("%d%d%d",&u,&v,&val);
      // printf("%d %d\n",u,v);
      printf("%d\n",go(u,v,val));
    }
  }
}