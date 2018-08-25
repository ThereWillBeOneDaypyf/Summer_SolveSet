#include<bits/stdc++.h>
using namespace std;

struct Node
{
  char op;
  int pos;
  bool operator<(const Node& rhs) const
  {
    return op < rhs.op || (op == rhs.op && pos < rhs.pos);
  }
};

const int N = 4e5 + 7;

bool vis[N];

int main()
{
  int n,m;
  while(cin >> n >> m)
  {
    string s;
    cin >> s;
    memset(vis,0,sizeof(vis));
    vector<Node> v;
    for(int i = 0;i < n;i ++)
      v.push_back({s[i],i});
    sort(v.begin(),v.end());
    for(int i = 0;i < m;i ++)
      vis[v[i].pos] = 1;
    for(int i = 0;i < n;i ++)
    {
      if(!vis[i])
        cout << s[i];
    }
    cout << endl;
  }
}