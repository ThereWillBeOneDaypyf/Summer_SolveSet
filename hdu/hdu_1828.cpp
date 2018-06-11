#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N = 2e4 + 7;
const int RET = 1e4 + 1;
struct  Tree
{
  int l,r;
  int cnt;
  int len;
}t1[N * 4],t2[N * 4];

struct Seg
{
  int pos;
  int l,r;
  int val;
  Seg() {}
  Seg(int _pos,int _l,int _r,int _val) : pos(_pos),l(_l),r(_r),val(_val) {}
  bool operator < (const Seg& rhs) const
  {
    return pos < rhs.pos || (pos == rhs.pos && val > rhs.val);
  }
};

vector<Seg> qry1,qry2;

void build(Tree* t,int l,int r,int step)
{
  t[step].l = l,t[step].r = r;
  t[step].cnt = 0;
  t[step].len = 0;
  if(l == r)
    return;
  int mid = (l + r) / 2;
  build(t,l,mid,step * 2);
  build(t,mid + 1, r, step * 2 + 1);
}

void push_up(Tree* t,int step)
{
  if(t[step].cnt) 
  {
    t[step].len = t[step].r - t[step].l + 1;
  }
  else if(t[step].l == t[step].r)
    t[step].len = 0;
  else t[step].len = t[step * 2].len + t[step * 2 + 1].len;
  // cout << t[step].l << " " << t[step].r  << " " << t[step].cnt << " " << t[step].len << endl;
}

void update(Tree* t,int l,int r,int val,int step)
{
  if(t[step].l == l && t[step].r == r)
  {
    t[step].cnt += val;
    push_up(t,step);
    return;
  }
  int mid = (t[step].l + t[step].r) / 2;
  if(r <= mid)
    update(t,l,r,val,step * 2);
  else if(l > mid)
    update(t,l,r,val,step * 2 + 1);
  else update(t,l,mid,val,step * 2),update(t,mid + 1,r,val,step * 2 + 1);
  push_up(t,step);
}

bool vis[N];

int main()
{
  int n;
  int ka = 0;
  int T;
  // scanf("%d",&T);
  // while(T--)
  while(scanf("%d",&n) == 1)
  {
    // scanf("%d",&n);
    qry1.clear(),qry2.clear();
    for(int i = 0;i < n;i ++)
    {
      int x,y,xx,yy;
      scanf("%d%d%d%d",&x,&y,&xx,&yy);
      Seg temp1(x,y,yy,1);
      Seg temp2(xx,y,yy,-1);
      Seg temp3(y,x,xx,1);
      Seg temp4(yy,x,xx,-1);
      qry1.push_back(temp1);
      qry1.push_back(temp2);
      qry2.push_back(temp3);
      qry2.push_back(temp4);
    }
    sort(qry1.begin(),qry1.end());
    sort(qry2.begin(),qry2.end());
    build(t1,1,N - 1,1);
    build(t2,1,N - 1,1);
    long long ans = 0;
    long long last = 0;
    for(int i = 0;i < qry1.size();i ++)
    {
      Seg se = qry1[i];
      update(t1,se.l + RET,se.r + RET - 1,se.val,1);
      ans += abs(last - t1[1].len);
      last = t1[1].len;
      // cout << last << endl;
    }
    last = 0;
    // int cnt = 0;
    for(int i = 0;i < qry2.size();i ++) 
    {
      Seg se = qry2[i];
     // cout << last << endl;
      update(t2,se.l + RET,se.r + RET - 1,se.val,1);
      ans += abs(last - t2[1].len);
      last = t2[1].len;
    }
    // cout << cnt << endl;
    // printf("Case #%d:\n%lld\n",++ka,ans);
    printf("%lld\n",ans);
  }
}