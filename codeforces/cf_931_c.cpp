#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  while(cin >> n)
  {
    vector<int> v;
    long long sum = 0;
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      v.push_back(x);
      sum += x;
    }
    long long Min = *min_element(v.begin(),v.end());
    long long Max = *max_element(v.begin(),v.end());
    if(Max - Min < 2)
    {
      cout << n << endl;
      for(int i = 0;i < n;i ++)
      {
        if(i)
          cout << " ";
        cout << v[i];
      }
      cout << endl;
      continue;
    }
    long long cnt[3];
    memset(cnt,0,sizeof(cnt));
    for(auto ele : v)
      cnt[ele - Min]++;
    long long ans_x,ans_y,ans_z;
    long long ans = n;
    for(long long x = 0;x <= n;x ++)
    {
      long long ret = sum - 1LL * x * Min;
      long long ret_cnt = n - x;
      long long y = 1LL * (Min + 2) * ret_cnt - ret;
      long long z = ret - 1LL * (Min + 1) * ret_cnt;
      if(y < 0 || y > n || z < 0 || z > n)
        continue;
      long long cur_dif = min(cnt[0],x) + min(cnt[1], y) + min(cnt[2],z);
      if(cur_dif <= ans)
      {
        ans_x = x;
        ans_y = y;
        ans_z = z;
        ans = cur_dif;
      }
    }
    cout << ans << endl;
    if(ans == n)
    {
      for(int i = 0;i < v.size();i ++)
      {
        if(i)
          cout << " ";
        cout << v[i];
      }
      cout << endl;
      continue;
    }
    vector<int> res(ans_x,Min);
    for(int i = 0; i < ans_y;i ++)
      res.push_back(Min + 1);
    for(int i = 0;i < ans_z;i ++)
      res.push_back(Min + 2);
    for(int i = 0;i < res.size(); i++)
    {
      if(i)
        cout << " ";
      cout << res[i];
    }
    cout << endl;
  }
}