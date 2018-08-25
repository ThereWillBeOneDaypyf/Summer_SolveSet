#include<bits/stdc++.h>
using namespace std;

int flag = 1;

int a[3] = {25,50,100};
int cnt[3];

void dfs(int pos,int cur)
{
  if(pos < 0)
  {
    if(cur)
      flag = 0;
    return;
  }
  if(cur >= a[pos])
  {
    if(cnt[pos])
    {
      cnt[pos] --;
      dfs(pos - 1,cur - a[pos]);
      return;
    }
  }
  dfs(pos - 1,cur);
}

int main()
{
  int n;
  while(cin >> n)
  {
    vector<int> v;
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      v.push_back(x);
    }
    memset(cnt,0,sizeof(cnt));
    flag = 1;
    for(int i = 0;i < n;i ++)
    {
      dfs(2,v[i] - 25);
      if(v[i] == 25)
        cnt[0] ++;
      else if(v[i] == 50)
        cnt[1] ++;
      else cnt[2] ++;
      if(!flag)
        break;
    }
    if(flag)
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}