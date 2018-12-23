#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

struct Tree
{
  int l,r;
  int cnt[26];
  int vis;
}t[N * 4];

const int MOD = 1e9 + 7;

string s;

void push_up(int);

void build(int l,int r,int step)
{
  t[step].l = l, t[step].r = r;
  t[step].vis = 0;
  memset(t[step].cnt,0,sizeof(t[step].cnt));
  if(l == r)
  {
    t[step].cnt[s[l - 1] - 'a'] ++;
    return;
  }
  int mid = (l + r) / 2;
  build(l,mid,step * 2);
  build(mid + 1,r ,step * 2 + 1);
  push_up(step);
}

void push_down(int step)
{
  if(!t[step].vis)
    return;
  int temp[26];
  for(int i = 0;i < 26;i ++)
    temp[i] = t[step * 2].cnt[i];
  for(int i = 0;i < 26;i ++)
    t[step * 2].cnt[(i + t[step].vis) % 26] = temp[i];
  for(int i = 0;i < 26;i ++)
    temp[i] = t[step * 2 + 1].cnt[i];
  for(int i = 0;i < 26;i ++)
    t[step * 2 + 1].cnt[(i + t[step].vis) % 26] = temp[i];
  t[step * 2].vis += t[step].vis;
  t[step * 2 + 1].vis += t[step].vis;
  t[step].vis = 0;
}

void push_up(int step)
{
  for(int i = 0;i < 26;i ++)
    t[step].cnt[i] = t[step * 2].cnt[i] + t[step * 2 + 1].cnt[i];
}

void update(int l,int r,int val,int step)
{
  if(t[step].l == l && t[step].r == r)
  {
    t[step].vis += val;
    t[step].vis %= 26;
    int temp[26];
    for(int i = 0;i < 26;i ++)
      temp[i] = t[step].cnt[i];
    for(int i = 0;i < 26;i ++)
      t[step].cnt[(val + i) % 26] = temp[i];
    return;
  }
  int mid = (t[step].l + t[step].r) / 2;
  push_down(step);
  if(r <= mid)
    update(l,r,val,step * 2);
  else if(l > mid)
    update(l,r,val,step * 2 + 1);
  else update(l,mid,val,step * 2), update(mid + 1,r, val, step * 2 + 1);
  push_up(step);
}

vector<int> query(int l,int r,int step)
{
  if(t[step].l == l && t[step].r == r)
  {
    return vector<int>(t[step].cnt,t[step].cnt + 26);
  }
  int mid = (t[step].l + t[step].r) / 2;
  push_down(step);
  if(r <= mid)
    return query(l,r,step * 2);
  else if(l > mid)
    return query(l,r,step * 2 + 1);
  else 
  {
    vector<int> temp1 = query(l,mid,step * 2), temp2 = query(mid + 1,r,step * 2 + 1);
    for(int i = 0;i < 26;i ++)
      temp1[i] += temp2[i];
    return temp1;
  }
}

long long pow_mod(long long x)
{
  if(!x)
    return 1;
  long long temp = pow_mod(x / 2);
  temp = temp * temp % MOD;
  if(x % 2)  
    temp *= 2;
  temp %= MOD;
  return temp;
}

long long get_ans(vector<int>& res)
{
  long long ans = 1;
  int has = 0;
  for(int i = 0; i < 26;i ++)
  {
    if(res[i])
    {
      has ++;
      ans *= pow_mod(res[i] - 1);
      ans %= MOD;
    }
  }
  ans = ans * (has + 1);
  ans %= MOD;
  ans --;
  ans += MOD;
  ans %= MOD;
  return ans;
}

int main()
{
  ios :: sync_with_stdio(false);
  int n,q;
  while(cin >> n >> q)
  {
    cin >> s;
    build(1,s.size(),1);
    for(int i = 0;i < q;i ++)
    {
      int ty;
      cin >> ty;
      int l,r;
      cin >> l >> r;
      l ++,r ++;
      if(ty == 1)
      {
        int val;
        cin >> val;
        update(l,r,val,1);
      }
      else 
      {
        vector<int> rua = query(l,r,1);
        cout << get_ans(rua) << endl;
      }
    }
  }
}