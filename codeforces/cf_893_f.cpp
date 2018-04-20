#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

struct Tree
{
  int Min;
  Tree*  lt,*rt;
  Tree() : lt(nullptr),rt(nullptr){Min = 1e9 + 7;}
};

vector<Tree*> root;
int id[N];
vector<int> G[N];
int dep[N];
int a[N];
int n;

void init()
{
  root.clear();
  for(int i = 0;i < N;i ++)
    G[i].clear();
}

Tree* new_node()
{
  return new Tree;
}

void push_up(Tree* r)
{
  int lval = (r -> lt == nullptr ? 1e9 + 7 : r -> lt -> Min);
  int rval = (r -> rt == nullptr ? 1e9 + 7 : r -> rt -> Min);
  r -> Min = min(lval,rval);
}

void update(Tree* rr,int l,int r,int x,int val)
{
  if(l == r) 
  {
    rr -> Min = min(val, rr->Min);
    return;
  }
  int mid = (l + r ) / 2;
  if(x <= mid)
  {
    if(rr -> lt == nullptr)
      rr -> lt = new_node();
    update(rr -> lt,l,mid,x,val);
  }
  else 
  {
    if(rr -> rt == nullptr)
      rr -> rt = new_node();
    update(rr -> rt,mid + 1, r, x, val);
  }
  push_up(rr);
}

Tree* merge(Tree* lhs,Tree* rhs)
{
  if(lhs == nullptr && rhs == nullptr)
    return nullptr;
  else if(rhs == nullptr)
    return lhs;
  else if(lhs == nullptr)
    return rhs;
  else
  {
    Tree* cur_r = new_node();
    cur_r -> Min = min(rhs -> Min,lhs -> Min);
    cur_r -> lt = merge(lhs -> lt,rhs -> lt);
    cur_r -> rt = merge(lhs -> rt,rhs -> rt);
    return cur_r;
  }
}

void dfs(int u,int fa,int d)
{
  Tree* rt = new_node();
  root.push_back(rt);
  id[u] = root.size() - 1; 
  dep[u] = d;
  update(rt,1,n,dep[u],a[u]);
  for(auto v : G[u])
  {
    if(v == fa)
      continue;
    dfs(v,u,d + 1);
    root[id[u]] = merge(root[id[u]],root[id[v]]);
  }
}

int query(Tree* rr,int l,int r,int ql,int qr)
{
  if(rr == nullptr)
    return 1e9 + 8;
  if(l == ql && r == qr)
    return rr -> Min;
  int mid = (l + r) / 2;
  if(qr <= mid)
    return query(rr -> lt,l, mid,ql,qr);
  else if(ql > mid)
    return query(rr -> rt,mid + 1, r,ql,qr);
  else return min(query(rr -> lt,l,mid,ql,mid),query(rr -> rt,mid + 1,r,mid + 1,qr));
}
void debug(Tree* rr,int l,int r)
{
  if(rr == nullptr)
    return;
  if(l == r)
  {
    cout << "dep : " << r << " " << rr->Min;
    return;
  }
  int mid = (l + r) / 2;
  debug(rr -> lt,l , mid);
  debug(rr -> rt,mid + 1, r);
}
int main()
{
  int rr;
  scanf("%d%d",&n,&rr);
  for(int i = 1;i <= n;i ++)
    scanf("%d",a + i);
  for(int i = 1;i < n;i ++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(rr,rr,1);
  // debug(root[0],1,n);
  // cout << endl;
  int m;
  scanf("%d",&m);
  int ans = 0;
  for(int i = 0;i < m;i ++)
  {
    int p,q;
    scanf("%d%d",&p,&q);
    int x = (p + ans) % n;
    x ++;
    int k = (q + ans) % n;
    ans = query(root[id[x]], 1, n,dep[x],min(dep[x] + k,n));
    printf("%d\n",ans);
  }
}