#include<bits/stdc++.h>
using namespace std;

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
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    if(v.size() < 2)
      cout << "NO" << endl;
    else cout << v[1] << endl;
  }
}