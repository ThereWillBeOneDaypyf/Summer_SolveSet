#include<bits/stdc++.h>
using namespace std;

int a[10];
int b[10];
int pos[10];
int n;
struct Node
{
  int x;
  int step;
};

long long bfs(int cur,int t)
{
  if(cur == t)
    return 0;
  long long cnt = 0;
  if(t > cur)
    swap(cur,t);
  if(cur > t)
  {
    while(cur / 2 >= t)
    {
      if(cur % 2)
      {
        cur --;
        cnt ++;
      }
      cur /= 2;
      cnt ++;
    }
    cnt += (cur - t);
  }
  else 
  {
    while(cur * 2 <= t)
    {
      cur *= 2;
      cnt ++;
    }
    cnt += (t - cur);
  }
  return cnt;
}

int vis[10];

void dfs(int i,int& cnt)
{
  if(vis[i])
    return;
  cnt ++;
  vis[i] = 1;
  dfs(pos[i],cnt);
}

int count_swap()
{
  int cnt = 0;
  memset(vis,0,sizeof(vis));
  for(int i = 0;i < n;i ++)
  {
    if(vis[i])
      continue;
    dfs(i,cnt);
    cnt--;
  }
  return cnt;
}

int main()
{
  ios :: sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--)
  {
    cin >> n;
    for(int i = 0;i < n;i ++)
      pos[i] = i;
    for(int i = 0;i < n;i ++)
      cin >> a[i];
    for(int i = 0;i < n;i ++)
      cin >> b[i];
    long long ans = 1e18 + 7;
    do{
      long long cnt = count_swap();
      for(int i = 0;i < n;i ++)
        cnt += bfs(a[pos[i]],b[i]);
      ans = min(ans,cnt);
      if(ans == 0)
        break;
    }while(next_permutation(pos,pos + n));
    cout << ans << endl;
  }
} 