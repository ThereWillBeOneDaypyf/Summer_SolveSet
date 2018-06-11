#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;


map<int,int> dp;
int a[N];

int main()
{
  int n;
  while(cin >> n) 
  {
    dp.clear();
    for(int i = 1;i <= n;i ++)
      cin >> a[i];
    int Max = 1;
    int ans_pos = 1;
    for(int i = 1;i <= n;i ++)
    {
      dp[a[i]] = dp[a[i] - 1] + 1;
      if(dp[a[i]] >= Max)
      {
        ans_pos = i;
        Max = dp[a[i]];
      }
    }
    vector<int> ans;
    Max = a[ans_pos];
    for(int i = n;i >= 1;i --) 
    {
      if(a[i] == Max)
      {
        ans.push_back(i);
        Max --;
      }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i ++)
    {
      if(i)
        cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
}