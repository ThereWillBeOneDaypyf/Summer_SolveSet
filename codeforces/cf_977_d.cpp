#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;

int vis[N];

struct Node
{
  unsigned long long cnt_2,cnt_3;
  int id;
  bool operator < (const Node& rhs) const
  {
    return cnt_3 > rhs.cnt_3 || (cnt_3 == rhs.cnt_3 && cnt_2 < rhs.cnt_2);
  }
};

int main()
{
  unsigned long long n;
  while(cin >> n)  
  {
    memset(vis,0,sizeof(vis));
    vector<pair<unsigned long long,unsigned long long> > v;
    vector<unsigned long long> tar;
    unsigned long long cur = 0;
    pair<unsigned long long,unsigned long long> cur_sta = make_pair(0,0);
    vector<Node> f; 
    for(unsigned long long i = 0;i < n;i ++)
    {
      unsigned long long x;
      cin >> x;
      tar.push_back(x);
      unsigned long long t2 = 0,t3 = 0;
      while(x % 2 == 0)
      {
        t2 ++;
        x /= 2;
      }
      while(x % 3 == 0)
      {
        t3 ++;
        x /= 3;
      }
      v.push_back(make_pair(t2,t3));
      if(t3 > cur_sta.second || (t3 == cur_sta.second && t2 < cur_sta.first))
      {
        cur_sta = make_pair(t2,t3);
        cur = i;
      }
      f.push_back({t2,t3,(int)i});
    }
    sort(f.begin(),f.end());
    for(int i = 0;i < f.size();i ++)
    {
      if(i)
        cout << " ";
      cout << tar[f[i].id];
    }
    cout << endl;
    // vector<unsigned long long> ans;
    // ans.push_back(cur);
    // vis[cur] = 1;
    // cout << cur_sta.first << " " << cur_sta.second << endl;
    // for(unsigned long long i = 1;i < n;i ++)
    // {
    //   for(unsigned long long j = 0;j < n;j ++)
    //   {
    //     if(vis[j])
    //       continue;
    //     pair<unsigned long long,unsigned long long> tar_sta = v[j];
    //     if((tar_sta.first - cur_sta.first == 1 && tar_sta.second == cur_sta.second) || (tar_sta.first == cur_sta.first && tar_sta.second + 1 == cur_sta.second))
    //     {
    //       ans.push_back(j);
    //       vis[j] = 1;
    //       cur_sta = tar_sta;
    //       break;
    //     }
    //   }
    // }
    // for(unsigned long long i = 0;i < ans.size();i ++)
    // {
    //   if(i)
    //     cout << " ";
    //   cout << tar[ans[i]];
    // }
    // cout << endl;
  }
}