#include<bits/stdc++.h>
using namespace std;

int vis[100];

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n,k;
    cin >> n >> k;
    memset(vis,0,sizeof(vis));
    int id = 1;
    int cur_id = 0;
    for(int i = 1;i < n;i ++)
    {
      id = 0; 
      while(id != k)
      {
        cur_id ++;
        if(cur_id > n)
          cur_id = 1;
        while(vis[cur_id])
        {
          cur_id ++;
          if(cur_id > n)
            cur_id = 1;
        }
        id ++;
      }
      vis[cur_id] = 1;
    }
    for(int i = 1;i <= n;i ++)
      if(!vis[i])
      {
        cout << i << endl;
        break;
      }
  }
}