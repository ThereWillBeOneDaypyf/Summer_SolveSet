#include<bits/stdc++.h>
using namespace std;

map<int,string> tran;

void init()
{
  for(int i = 0;i <= 17575;i ++)
  {
    string s;
    int temp = i;
    for(int j = 0;j < 3;j ++)
    {
      char x = 'a' + (temp % 26);
      s.push_back(x);
      temp /= 26;
    }
    reverse(s.begin(),s.end());
    tran[i] = s;
  }
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
    int cur = 0;
    for(int i = 1;i <= n;i ++)
    {
      cur *= 10;
      char x;
      cin >> x;
      x -= '0';
      cur += x;
      if(i % 5 == 0)
      {
        cout << tran[cur];
        cur = 0;
      }
    }
    cout << endl;
  }
}