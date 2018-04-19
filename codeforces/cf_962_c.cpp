#include<bits/stdc++.h>
using namespace std;

set<long long> num;

void init()
{
  for (int i = 1;; i ++)
  {
    if (1LL * i * i > 2e9)
      break;
    num.insert(1LL * i * i);
  }
}


int main()
{
  init();
  long long n;
  while (cin >> n)
  {
    vector<int> v;
    while (n)
    {
      v.push_back(n % 10);
      n /= 10;
    }
    int ans = -1;
    reverse(v.begin(), v.end());
    for (int i = 0; i < (1 << v.size()); i ++)
    {
      vector<int>temp;
      int cnt = 0;
      for (int j = 0; j < v.size(); j ++)
      {
        if (i & (1 << j))
        {
          temp.push_back(v[j]);
          cnt++;
        }
      }
      long long cur = 0;
      bool has_other = false;
      bool flag = true;
      for (auto ele : temp)
      {
        if (ele == 0 && !has_other)
        {
          flag = false;
          break;
        }
        else if (ele != 0)
          has_other = true;
        cur *= 10;
        cur += ele;
      }
      if (!flag)
        continue;
      if (num.count(cur))
      {
        if (ans == -1)
          ans = (int)v.size() - cnt;
        else ans = min(ans, (int)v.size() - cnt);
      }
    }
    cout << ans << endl;
  }
}
