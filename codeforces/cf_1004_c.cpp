#include<bits/stdc++.h>
using namespace std;


int main()
{
  int n;
  while(cin >> n)
  {
    set<int> s;
    map<int,int> cnt;
    vector<int> v;
    for(int i = 0;i < n;i ++)
    {
      int x;
      cin >> x;
      v.push_back(x);
      s.insert(x);
      cnt[x]++;
    }
    long long ans = 0;
    for_each(v.begin(),v.end(),[&](int x){
      cnt[x] --;
      if(cnt[x] == 0)
        cnt.erase(cnt.find(x));
      if(s.find(x) != s.end())
      {
        ans += cnt.size();
        s.erase(s.find(x));
      }
    });
    cout << ans << endl;
  }
}