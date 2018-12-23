#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
struct Edge
{
  int u,v;
  long long d;
  bool operator < (const Edge& rhs) const
  {
    return d > rhs.d;
  }
};

int fa[N],cnt[N];
long long a[N];
vector<Edge> e;

void init()
{ 
  for(int i = 0;i < N;i ++)
  {
     fa[i] = i, cnt[i] = 1;
  }
  e.clear();
}

int find(int x)
{
  if(fa[x] != x)
    fa[x] = find(fa[x]);
  return fa[x];
}

void merge(int a,int b)
{
  a = find(a), b = find(b);
  if(fa[a] != fa[b])
  {
    cnt[fa[b]] += cnt[fa[a]];
    fa[a] = fa[b];
  }
}

int main()
{
  int n,m;
  while(cin >> n >> m)
  {
    init();
    vector<int> id;
    for(int i = 1;i <= n;i ++)
    {
      cin >> a[i];
      id.push_back(i);
    }
    for(int i = 0;i < m;i ++)
    {
      int u,v;
      cin >> u >> v;
      e.push_back({u,v,min(a[u],a[v])});
    }
    sort(e.begin(),e.end());
    long long sum = 0;
    for(auto temp : e)
    {
      int u = temp.u, v = temp.v;
      long long d = temp.d;
      if(find(u) == find(v))
        continue;
      sum += d * (1LL * cnt[find(u)] * cnt[find(v)]);
      merge(u,v);
    }
    cout << (2.0 * sum) / (1.0 * n * (n - 1)) << endl;
  }
}