#include<bits/stdc++.h>
using namespace std;

struct Node
{
  string s;
  int id;
};

bool judge(vector<Node>& v)
{
  int Min = 1000;
  int pos = -1;
  int last = -1;
  for(int i = 0;i < v.size();i ++)
  {
    last = pos;
    // cout << " **  " << i << endl;
    for(int j = 0;j < v.size();j ++)
    {
      if(v[j].id != -1)
        continue;
      if(pos == -1)
        pos = j; 
      else
      {
        if(last == - 1)
        {
          if(v[j].s.find(v[pos].s) == string::npos)
            pos = j;
        }
        else
        {
          if(last == pos && v[j].s.find(v[last].s) != string::npos)
            pos = j;
          else if(last != pos && v[j].s.find(v[last].s) != string::npos && v[j].s.find(v[pos].s) == string::npos)
            pos = j;
        }
      }
      // cout << pos << endl;
    }
    // cout << "final pos : " << pos << endl;
    if(last != -1 && v[pos].s.find(v[last].s) == string::npos)
      return false;
    if(v[pos].id != -1)
      return false;
    v[pos].id = i;
  }
  return true;
}

int main()
{
  int n;
  while(cin >> n)
  {
    vector<Node> v;
    for(int i = 0;i < n;i ++)
    {
      string s;
      cin >> s;
      v.push_back({s,-1});
    }
    if(judge(v))
    {
      cout << "YES" << endl;
      sort(v.begin(),v.end(),[](Node a,Node b){return a.id < b.id;});
      for_each(v.begin(),v.end(),[](Node a){ cout << a.s << endl;});
    }
    else cout << "NO" << endl;
  }
}