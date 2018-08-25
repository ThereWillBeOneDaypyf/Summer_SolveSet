#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

struct Tree
{
  int Max;
  int lt,rt;
  int vis;
} t[N * N * 10];

int cnt = 0;

int root[N];
queue<queue<int> > q;

void init()
{
  memset(root,0,sizeof(root));
  cnt = 0;
}

int new_node()
{
  int step;
  if(!q.empty())
  {
    auto tep = q.front();
    step = tep.front();
    if(tep.empty())
      q.pop();
  }
  else step = ++ cnt;
  t[step].lt = t[step].rt = 0;
  t[step].Max = t[step].vis = 0;
  return cnt;
}

void cp(Tree& x,Tree y)
{
  x.lt = y.lt,x.rt = y.rt;
  x.Max = y.Max,x.vis = y.vis;
}

void push_up(int step)
{
  t[step].Max = max(t[t[step].lt].Max,t[t[step].rt].Max);
}



void update(int ql,int qr,int l,int r,int val,int& x,int y,queue<int>& qq)
{
  x = new_node();
  int t_x = x;
  qq.push(t_x);
  cp(t[x],t[y]);
  if(l == ql && r == qr)
  {
    t[x].Max += val;
    t[x].vis += val;
    return;
  }
  int mid = (l + r) / 2;
  if(qr <= mid)
    update(ql,qr,l,mid,val,t[x].lt,t[y].lt,qq);
  else if(ql > mid)
    update(ql,qr,mid + 1,r,val,t[x].rt,t[y].rt,qq);
  else update(ql,mid,l,mid,val,t[x].lt,t[y].lt,qq),update(mid + 1,qr,mid + 1,r,val,t[x].rt,t[y].rt,qq);
  push_up(x);
}

int dp[N];
struct Node
{
  int l, r, val;
};
vector<Node> v;

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n, m;
    init();
    v.clear();
    scanf("%d%d", &n, &m);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
      int l, r, val;
      scanf("%d%d%d", &l, &r, &val);
      v.push_back({l, r, val});
    }
    sort(v.begin(), v.end(), [](Node a, Node b) {
      return (a.l < b.l) || (a.l == b.l && a.r < b.r);
    });
    int st = 0;
    while (st < n && v[st].l == 1)
    {
      dp[st] = v[st].val;
      queue<int> tmp;
      update(v[st].l,v[st].r,1,m,v[st].val,root[st + 1],0,tmp);
      st++;
    }
    for (int i = st; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (v[j].r >= v[i].l - 1)
        {
          if (dp[j] == -1)
            continue;
          queue<int> tmp;
          update(v[i].l,v[i].r,1,m,v[i].val,root[n + 1],root[j + 1],tmp);
          int cur_ans = t[root[n + 1]].Max;
          if (dp[i] == -1 || dp[i] > cur_ans)
          {
            dp[i] = cur_ans;
            root[i + 1] = root[n + 1];
          }
          else q.push(tmp);
        }
      }
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
      if (v[i].r != m)
        continue;
      if (dp[i] == -1)
        continue;
      if (ans == -1)
        ans = dp[i];
      else
        ans = min(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
}