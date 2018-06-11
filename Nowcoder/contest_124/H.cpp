#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

struct Q
{
  int l,r;
  int val;
  int id;
  bool operator < (const Q& rhs) const
  {
    return l < rhs.l || (l == rhs.l && r < rhs.r);
  }
};

vector<int> v;
vector<Q> qry;

int cnt[N];
int a[N];
int ans[N];

int get_id(int tar)
{
  return lower_bound(v.begin(),v.end(),tar) - v.begin();
}

void update(int pos,int val)
{
  cnt[a[pos]] += val;
}


int main()
{
  int n;
  while(scanf("%d",&n) == 1)
  {
    memset(cnt,0,sizeof(cnt));
    v.clear();
    qry.clear();
    for(int i = 1;i <= n;i ++)
    {
      scanf("%d",a + i);
      v.push_back(a[i]);
    }
    int q;
    scanf("%d",&q);
    for(int i = 0;i < q;i ++)
    {
      int l,r,val;
      scanf("%d%d%d",&l,&r,&val);
      qry.push_back({l,r,val,i});
      v.push_back(val);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    sort(qry.begin(),qry.end());
    for(int i = 1;i <= n;i ++)
      a[i] = get_id(a[i]);
    int l=2,r=1;
    for(int i=0;i<q;i++)
    {
      while(l>qry[i].l) update(--l,1);
      while(r<qry[i].r) update(++r,1);
      while(l<qry[i].l) update(l++,-1);
      while(r>qry[i].r) update(r--,-1);
      ans[qry[i].id] = cnt[get_id(qry[i].val)];
    }
    for(int i = 0;i < q;i ++)
      printf("%d\n",ans[i]);
  }
}