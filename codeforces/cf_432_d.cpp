#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

char s[N];
int nxt[N];
long long cnt[N];
int len;

void solve_nxt()
{
  len = strlen(s);
  nxt[0] = -1;
  int j = 0;
  int k = -1;
  while(j < len)
  {
    if(k == -1 || s[j] == s[k])
    {
      nxt[++j] = ++ k;
    }
    else k = nxt[k];
  }
}

void dfs_ans(int l,int& sum)
{
  if(!l)
  {
    printf("%d\n",sum);
    return;
  }
  sum ++;
  dfs_ans(nxt[l],sum);
  printf("%d %lld\n",l,cnt[l]);
}

int main()
{
  while(scanf("%s",s) == 1)
  {
    solve_nxt();
    for(int i = 0;i <= len;i ++)
      cnt[i] = 1;
    for(int i = len;i >= 0;i --)
      if(nxt[i] != -1)
        cnt[nxt[i]] += cnt[i];
    int sum = 0;
    dfs_ans(len,sum);
  }
}