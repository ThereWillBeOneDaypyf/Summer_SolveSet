#include<bits/stdc++.h>
using namespace std;

vector<int> v;

bool judge(int val)
{
  vector<int> v;
  int temp = val;
  while(temp)
  {
    v.push_back(temp % 10);
    temp /= 10;
  }
  for(int i = 0;i < v.size();i ++)
  {
    int res = 0;
    for(int j = 0;j < v.size();j ++)
    {
      res *= 10;
      res += v[(i + j) % v.size()];
    }
    if(res % val)
      return false;
  }
  return true;
}

void init()
{
  for(int i = 1;i <= 9;i ++)
  {
    for(int j = 1;j <= 9;j ++)
    {
      vector<int> temp(i,j);
      int res= 0 ;
      for(auto ele : temp)
      {
        res *= 10;
        res += ele;
      }
      v.push_back(res);
    }
  }
  v.push_back(142857);
  sort(v.begin(),v.end());
}

int main()
{
  init();
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    cout << upper_bound(v.begin(),v.end(),n) - v.begin() << endl;
  }
}