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
    sort(v.begin(),v.end(),[](int a,int b){return a > b;});
    if(n == 1)
    {
      cout << v[0] << endl;
      continue;
    }
    else
    {
      cout << v[n / 2] << endl;
    }
  }
}