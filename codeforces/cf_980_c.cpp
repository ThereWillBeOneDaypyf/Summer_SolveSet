#include<bits/stdc++.h>
using namespace std;

#define DEBUG_CNT 15

int vis[256];
vector<int> v;
int n,k;

void debug()
{
  for(int i = 0;i < DEBUG_CNT;i ++)
    cout << vis[i] << " ";
  cout << endl;
}

int main()
{
  while(cin >> n >> k)
  {
    memset(vis,-1,sizeof(vis));
    v.clear();
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      v.push_back(x);
    }
    for(int i = 0;i < n;i ++)
    {
      if(vis[v[i]] != -1)
        continue;
      int pre = n + 1;
      int j;
      for(j = v[i];j >= max(0,v[i] - k + 1);j --)
      {
        if(vis[j] != -1)
        {
          if(v[i] - vis[j] + 1 <= k)
          {
            pre = vis[j];
          }
          j ++;
          break;
        }
        pre = j;
      }
      for(int j = pre;j <= v[i];j ++)
        vis[j] = pre;
      // debug();
    }
    for(int i = 0;i < n;i ++)
    {
      if(i)
        cout << " ";
      cout << vis[v[i]];
    }
    cout << endl;
  }
}