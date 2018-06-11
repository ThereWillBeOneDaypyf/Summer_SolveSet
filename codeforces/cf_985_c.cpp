#include<bits/stdc++.h>
using namespace std;


int main()
{
  int n,k,l;
  while(cin >> n >> k >> l)
  {
    vector<int> v;
    for(int i = 0;i < n * k; i++)
    {
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(),v.end());
    int cnt = upper_bound(v.begin(),v.end(),v[0] + l) - v.begin();
    if(cnt < n)
    {
      cout << 0 << endl;
    }
    else
    {
      long long sum = 0;
      priority_queue<int> q;
      int cur = 0;
      for(int i = 0;i < cnt;i ++)
      {
        if(i % k == 0)
        {
          sum += v[i];
          n--;
        }
        else 
        {
          q.push(v[i]);
        }
      }
      for(int i = 0;i < n;i ++)
      {
        sum += q.top();
        q.pop();
      }
      cout << sum << endl;
    }
  }
}