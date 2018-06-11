#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;


int main()
{
  int n;
  while(cin >> n)
  {
    vector<int> v;
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      v.push_back(x);
    }
    if(n == 1)
    {
      cout << 0 << endl;
      continue;
    }
    int Min = n + 1;
    for(int i = -1;i <= 1;i ++)
    {
      for(int j = -1;j <= 1;j ++)
      {
        vector<int> temp(v);
        temp[0] += i;
        temp[1] += j;
        int cur_d = temp[1] - temp[0];
        int cnt = 0;
        if(i)
          cnt ++;
        if(j)
          cnt ++;
        int flag = 1;
        for(int k = 2;k < temp.size();k ++)
        {
          int d = temp[k] - temp[k - 1];
          if(abs(d - cur_d) > 1)
          {
            flag = 0;
            break;
          }
          int dif = d - cur_d;
          if(dif)
            cnt++;
          temp[k] = temp[k - 1] + cur_d;
        }
        
        if(flag)
        {
          Min = min(Min,cnt);
        }
      }
    }
    if(Min > n)
      cout << - 1 << endl;
    else cout << Min << endl;
  }
}