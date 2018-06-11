#include<bits/stdc++.h>
using namespace std;


int main()
{
  int n,k;
  while(cin >> n >> k)
  {
    map<int,int> pos;
    vector<int> v;
    for(int i = 1;i <= n;i ++)
    {
      int x;
      cin >> x;
      v.push_back(x);
      pos[x] = i;
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    if(v.size() < k)
    {
      cout << "NO" << endl;
    }
    else
    {
      cout << "YES" << endl;
      for(int i = 0;i < k;i ++)
      {
        if(i)
          cout << " ";
        cout << pos[v[i]];
      }
      cout << endl;
    }
  }
}