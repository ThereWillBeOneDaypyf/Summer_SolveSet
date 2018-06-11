#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int fa[N];
int val[N];
int vis[N];
int cnt[N];
int sz = 0;
pair<int,int> a[N];
int n;
int Max_val = 0;
void init()
{
  for(int i = 1; i< N;i ++)
    fa[i] = i,val[i] = 1;
  memset(cnt,0,sizeof(cnt));
  memset(vis,0,sizeof(vis));
  sz = 0;
}

int find(int x)
{
  if(x != fa[x])
    fa[x] = find(fa[x]);
  return fa[x];
}

void uni(int x,int y)
{
  x = find(x);
  y = find(y);
  if(fa[x] != fa[y])
  {
    cnt[val[fa[y]]] --;
    cnt[val[fa[x]]] --;
    val[fa[x]] += val[fa[y]];
    cnt[val[fa[x]]] ++;
    fa[y] = fa[x];
    Max_val = max(Max_val,val[fa[x]]);
  }
}


void merge(int pos)
{
  int has_merge = 0;
  cnt[1] ++;
  if(pos != 1 && vis[pos - 1])
  {
    uni(pos,pos - 1);
    has_merge ++;
  }
  if(pos != n && vis[pos + 1])
  {
    uni(pos,pos + 1);
    has_merge ++;
  }
  if(!has_merge)
    sz ++;
  else if(has_merge == 2)
    sz --;
  Max_val = max(Max_val,val[find(pos)]);
  vis[pos] = 1;
}

int main()
{
  while(cin >> n)
  {
    init();
    int Max = 0;
    int ans = -1;
    for(int i = 1;i <= n;i ++)
    {
      int x;
      cin >> x;
      a[i] = make_pair(x,i);
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1;i <= n;i ++)
    {
      merge(a[i].second);  
      if(cnt[Max_val] == sz)
      {
        if(sz > Max)
        {
          ans = a[i].first+ 1;
          Max = sz;
        }
      }
    }
    cout << ans << endl;
  }
}