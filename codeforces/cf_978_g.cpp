#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int vis[N];

struct Node
{
  int l,r;
  int val;
  int id;
  bool operator <(const Node& rhs) const
  {
    return r > rhs.r;
  }
};

int main()
{
  int n,m;
  while(cin >> n >> m)
  {
    memset(vis,0,sizeof(vis));
    vector<Node> v;
    for(int i = 0;i < m;i ++)
    {
      int l,r,val;
      cin >> l >> r >> val;
      v.push_back({l,r,val,i + 1});
    }
    sort(v.begin(),v.end(),[](Node a,Node b){ return a.l < b.l;});
    priority_queue<Node> q;
    int pos = 0;
    int flag = 1;
    for(int i = 1;i <= n;i ++)
    {
      while(v[pos].l == i) 
      {
        q.push(v[pos]);
        pos ++;
      }
      if(vis[i])
        continue;
      if(!q.empty())
      {
        auto temp = q.top();
        q.pop();
        if(i > temp.r)
        {
          flag = 0;
          break;
        }
        else 
        {
          vis[i] = temp.id;
          temp.val --;
          if(temp.val)
            q.push(temp);
          else 
          {
            if(vis[temp.r])
              flag = 0;
            vis[temp.r] = m + 1;
          }
        }
      }
    }
    if(!flag || !q.empty())
      cout << -1 << endl;
    else 
    {
      for(int i = 1;i <= n;i ++)
      {
        if(i != 1)
          cout << " " ;
        cout << vis[i];
      }
      cout << endl;
    }
  }
}