#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7; 

set<long long> s;
map<long long,pair<int,int> > pos;

void init()
{
  s.clear();
  pos.clear();
}


int main()
{
  int k;
  while(cin >> k)
  {
    init();
    int flag = 0;
    for(int i = 0;i < k;i ++)
    {
      long long sum = 0;
      vector<int> v;
      int n;
      cin >> n;
      for(int j = 0;j < n;j ++)
      {
        int x;
        cin >> x;
        sum += x;
        v.push_back(x);
      }
      if(flag)
        continue;
      for(int j = 0;j < n;j ++)
      {
        if(s.find(sum - v[j]) != s.end())
        {
          flag = 1;
          cout << "YES" << endl;
          cout << i + 1 << " " << j + 1 << endl;
          cout << pos[sum - v[j]].first << " " << pos[sum - v[j]].second << endl;
          break;
        }
      }
      for(int j = 0;j < n;j ++)
      {
        s.insert(sum - v[j]);
        pos[sum - v[j]] = make_pair(i + 1,j + 1);
      }
    }
    if(!flag)
      cout << "NO" << endl;
  }
}