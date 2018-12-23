#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k,p;
  while(cin >> n >> k >> p)
  {
    vector<int> v[2];
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      v[x % 2].push_back(x);
    }
    int odd_cnt = k - p;
    if(odd_cnt > v[1].size())
    {
      cout << "NO" << endl;
    }
    else
    {
      if((v[1].size() - odd_cnt) % 2 != 0)
      {
        cout << "NO" << endl;
      }
      else
      {
        if((v[1].size() - odd_cnt) / 2 + v[0].size() < p)
          cout << "NO" << endl;
        else
        {
          cout << "YES" << endl;
          if(p == 0)
          {
            for(int i = 0;i < odd_cnt - 1;i ++)
              cout << "1 " << v[1][i] << endl;
            cout << v[1].size() - odd_cnt + 1 + v[0].size();
            for(int i = odd_cnt - 1;i < v[1].size();i ++)
              cout << " " << v[1][i];
            for(int i = 0;i < v[0].size();i ++)
              cout << " " << v[0][i];
            cout << endl;
          }
          else
          {
            for(int i = 0;i < odd_cnt;i ++)
              cout << "1 " << v[1][i] << endl;
            int pos = odd_cnt;
            int cnt = odd_cnt;
            for(int i = 0;i < p - 1;i ++)
            {
              if(i < v[0].size())
              {
                cout << "1 " << v[0][i] << endl;
                cnt ++;
              }
              else
              {
                cout << "2 " << v[1][pos] << " " << v[1][pos + 1] << endl;
                pos += 2;
                cnt += 2;
              }
            }
            cout << n - cnt;
            for(int i = p - 1;i < v[0].size();i ++)
              cout << " " << v[0][i];
            for(int i = pos;i < v[1].size();i ++)
              cout << " " << v[1][i];
            cout << endl;
          }
        }
      }
    }
  }
}