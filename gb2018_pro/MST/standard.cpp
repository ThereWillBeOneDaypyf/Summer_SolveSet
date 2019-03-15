#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
struct Edge
{
  int u,v,d;
  bool operator< (const Edge& e) const 
  {
    return d < e.d;
  }
};

int fa[N];
int fa_e[N];
vector<Edge> edge,real_e;

void init()
{
  for(int i = 0;i < N;i ++)
    fa[i] = i,fa_e[i] = i;
  edge.clear();
}

int find(int f[],int x)
{
  if(f[x] != x)
    f[x] = find(f,f[x]);
  return f[x];
}

void merge(int f[],int u,int v)
{
  u = find(f,u), v = find(f,v);
  if(f[u] != f[v])
    f[u] = f[v];
}

long long Kruskal() 
{
  long long sum = 0;
  sort(real_e.begin(),real_e.end());
  for(auto ele : real_e)
  {
    int u = ele.u, v = ele.v;
    int d = ele.d;
    // cout << find(fa_e,u) << " " << find(fa_e,v) << endl;
    if(find(fa_e,u) == find(fa_e,v))
      continue;
    // cout << "add" << endl;
    sum += d;
    merge(fa_e,u,v);
  }
  return sum;
}
int id[N];

int main()
{
  int n,m,k;
  int T = 1;
  // freopen("1.out","w",stdout);
  while(T<= 55)
  {
    // fclose(stdin);
    string name = std::to_string(T);
    name += ".in";
    freopen(name.c_str(),"r",stdin);
    T++;
    printf("%s\n",name.c_str());
    while(scanf("%d%d%d", &n, &k, &m) == 3)
    {
      clock_t st = clock();
      init();
      for(int i = 1;i <= n;i ++)
      {
        int t;
        scanf("%d",&t);
        // cin >> t;
        id[i] = t;
      }
      for(int i = 0;i < m;i ++)
      {
        int u,v,c;
        // cin >> u >> v >> c;
        scanf("%d%d%d",&u,&v,&c);
        if(id[u] == id[v])
          continue;
        real_e.push_back({id[u],id[v],c});
      }
      // for(auto ele : real_e)
      //   cout << ele.u << " " << ele.v << " " << ele.d << endl;
      bool flag = true;
      long long ans = Kruskal();
      for(int i = 1;i <= k;i ++)
      {
        if(find(fa_e,i) != find(fa_e,1))
        {
          flag = false;
          break;
        }
      }
      if(!flag) 
      {
        puts("poor appleseQwQ");
        // cout << "poor appleseQwQ" << endl;
      }
      else printf("%lld\n",ans);
      printf("time : %.lfms\n",(clock()-st)*1000.0 / CLOCKS_PER_SEC);
      // else cout << ans << endl;
    }
  }
  // fclose(stdin);
  // getchar();
}
/*
6 2 8
1 1 1 2 2 2
1 2 1
2 3 2
1 3 3
3 4 6
4 5 1
4 6 3
5 6 2
1 6 2
*/