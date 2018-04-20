#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

long long c[N];
long long group[N];

int main()
{
  int n,k,m;
  while(cin >> n >> k >> m)
  {
    map<string,int> id;
    map<int,string> tran;
    for(int i = 1;i <= n;i ++)
    {
      string s;
      cin >> s;
      tran[i] = s;
    }
    for(int i = 1;i <= n;i ++)
      cin >> c[i];
    for(int i = 1;i <= k;i ++)
    {
      int cnt;
      cin >> cnt;
      group[i] = 1e9 + 7;
      for(int j = 0;j < cnt;j++)
      {
        int ind;
        cin >> ind;
        id[tran[ind]] = i;
        group[i] = min(group[i],c[ind]);
      }
    }
    long long sum = 0;
    for(int i = 0;i < m;i ++)
    {
      string s;
      cin >> s;
      sum += group[id[s]];
    }
    cout << sum << endl;
  }
}