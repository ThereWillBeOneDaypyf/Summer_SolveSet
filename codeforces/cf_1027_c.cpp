#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;

int cnt[N];

int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    memset(cnt,0,sizeof(cnt));
    cin >> n;
    vector<long long> ret;
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      cnt[x] ++;
      if(cnt[x] == 2)
        ret.push_back(x);
    }
    sort(ret.begin(),ret.end());
    vector<int> ans;
    double ans_res = 1e18 + 7;
    for(int i = 0;i < ret.size();i ++)
    {
      if(cnt[ret[i]] >= 4)
      {
        double res = 4;
        if(res < ans_res)
        {
          ans = vector<int>(4,ret[i]);
          ans_res = res;
        }
        break;
      }
      if(i < ret.size() - 1)
      {
        double res = 1.0 * (ret[i] + ret[i + 1]) * (ret[i] + ret[i + 1]) / (ret[i] * ret[i + 1]);
        if(res < ans_res)
        {
          ans_res = res;
          ans.clear();
          for(int j = 0;j < 2;j ++)
          {
            for(int k = 0;k < 2;k ++)
            {
              ans.push_back(ret[i + j]);
            }
          }
        }
      }
    }
    for_each(ans.begin(),ans.end(),[](int x) { cout << x << " "; });
    cout << endl;
  }
}