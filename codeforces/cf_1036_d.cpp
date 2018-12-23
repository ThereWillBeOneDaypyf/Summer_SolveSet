#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  ios::sync_with_stdio(false);
  while(cin >> n)
  {
    long long suma = 0;
    long long sumb = 0;
    vector<int> a,b;
    for(int i = 0; i< n;i ++)
    {
      int x;
      cin >> x;
      a.push_back(x);
      suma += x;
    }
    cin >> m;
    for(int j = 0;j < m;j ++)
    {
      int x;
      cin >> x;
      sumb += x;
      b.push_back(x);
    }
    if(suma != sumb)
    {
      cout << - 1 << endl;
      continue;
    }
    vector<long long> ans;
    int p_a = 0,p_b = 0;
    suma = 0,sumb = 0;
    while(p_a < a.size() || p_b < b.size())
    {
      if(suma > sumb)
      {
        sumb += b[p_b ++];
      }
      else suma += a[p_a ++];
      while(suma == sumb && suma != 0 && (p_a < a.size() || p_b < b.size()))
      {
        ans.push_back(suma);
        suma += a[p_a ++];
        sumb += b[p_b ++];
      }
    }
    if(ans.empty())
      cout << 1 << endl;
    else 
      cout << ans.size() + (suma != *ans.rbegin()) << endl;
  }
}