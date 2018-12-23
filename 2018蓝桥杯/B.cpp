#include <bits/stdc++.h>
using namespace std;
int n;

int get_ans(map<long long,int>& cnt,long long tar_val)
{
  // cout << tar_val << " " << cnt[tar_val] << endl;
  return cnt[tar_val];
}

void debug(int a,int b,int c,int d)
{
  cout << a << " " << b << " " << c <<  " " << d << endl;
}

int main()
{
  while (cin >> n)
  {
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> v[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      map<long long,int> tar;
      for (int j = i + 1; j < n; j++)
        tar[v[j]] ++;
      for (int j = i + 1; j < n - 1; j++)
      {
        tar[v[j]] --;
        long long tar_val = 1LL * v[i] * v[j];
        ans += get_ans(tar,tar_val);
        long long val1,val2;
        if (v[j] && (v[i] % v[j] == 0))
        {
          val1 = v[i] / v[j];
          if(val1 != tar_val)
            ans += get_ans(tar,val1);
        }
        if (v[i] && (v[j] % v[i] == 0))
        {
          val2 = v[j] / v[i];
          if(val2 != val1 && val2 != tar_val)
            ans += get_ans(tar,val2);
        }
      }
    }
    cout << ans << endl;
  }
}