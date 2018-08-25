#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int val;
  int pwd;
  int id;
  long long ans;
};

int main()
{
  int n,k;
  while(cin >> n >> k)
  {
    vector<Node> v;
    vector<Node> temp;
    for(int i = 0;i < n;i ++)
    {
      int p;
      cin >> p;
      v.push_back({0,p,i,0});
    }
    for(int i = 0;i < n;i ++)
      cin >> v[i].val;
    temp = v;
    sort(v.begin(),v.end(),[](Node a,Node b) { return a.pwd > b.pwd;});
    sort(temp.begin(),temp.end(),[](Node a,Node b) { return a.val > b.val; });
    queue<Node> q;
    for(int i = 0;i < k;i ++)
      q.push(temp[i]);
    int p = k;
    for(int i = 0;i < n;i ++)
    {
      queue<Node> temp_q;
      long long sum = 0;
      while(!q.empty())
      {
        auto t = q.front();
        q.pop();
        if(t.pwd < v[i].pwd)
        {
          temp_q.push(t);
          sum += t.val;
        }
      }
      while(p < n && temp_q.size() < k)
      {
        if(temp[p].pwd < v[i].pwd)
        {
          temp_q.push(temp[p]);
          sum += temp[p].val;
        }
        p++;
      }
      q = temp_q;
      v[i].ans = sum;
    }
    sort(v.begin(),v.end(),[](Node a,Node b) {return a.id < b.id; });
    for(int i = 0;i < n;i ++)
    {
      if(i)
        cout << " ";
      cout << v[i].ans + v[i].val;
    }
    cout << endl;
  }
}