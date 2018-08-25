#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int pre_sum[N];
int a[N];
int suf_sum[N];

int main()
{
  int n;
  while(cin >> n)
  {
    string s;
    cin >> s;
    int g = 0;
    for(int i = 0;i < n;i ++)
    {
      a[i + 1] = s[i] - '0';
      if(!a[i + 1])
        g ++;
    }
    memset(pre_sum,0,sizeof(pre_sum));
    memset(suf_sum,0,sizeof(suf_sum));
    int ans = 0;
    for(int i = 1;i <= n;i ++)
    {
      if(a[i])
        pre_sum[i] = 0;
      else 
        pre_sum[i] = pre_sum[i - 1] + 1; 
      ans = max(ans,pre_sum[i]);
    }
    for(int i = n;i >= 1;i --)
    {
      if(a[i])
        suf_sum[i] = 0;
      else suf_sum[i] = suf_sum[i + 1] + 1;
    }
    for(int i = 1;i <= n;i ++)
    {
      if(a[i])
      {
        int cur = suf_sum[i + 1] + pre_sum[i - 1];
        if(cur == g)
        {
          ans = max(ans,cur);
        }
        else 
        {
          ans = max(ans,cur + 1);
        }
      }
    }
    cout << ans << endl;
  }
}