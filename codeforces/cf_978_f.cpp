#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

map<int,vector<int> > cnt;
int add[N];

void init()
{
  memset(add,0,sizeof(add));
}

int main()
{
  int n,m;
  while(cin >> n >> m)
  {
    vector<int> v;
    cnt.clear();
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      v.push_back(x);
      cnt[x].push_back(i);
    }
    for(int i = 0;i < m;i ++)
    {
      int u,vv;
      cin >> u >> vv;
      u --,vv --;
      if(v[u] > v[vv])
        add[u] --;
      if(v[vv] > v[u])
        add[vv] --;
    }
    int sum = 0;
    for(auto it = cnt.begin();it != cnt.end();it ++)
    {
      for(auto ele : (*it).second)
      {
        add[ele] += sum;
      }
      sum += (*it).second.size();
    }
    for(int i = 0;i < n;i ++)
    {
      if(i)
        cout << " ";
      cout << add[i];
    }
    cout << endl;
  }
}