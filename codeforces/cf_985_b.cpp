#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 7;

int Map[N][N];

int cnt[N];
int n,m;

bool judge(int pos)
{
  int flag = 1;
  for(int i = 0;i < m;i ++)
  {
    cnt[i] -= Map[pos][i];
    if(cnt[i] == 0)
      flag = 0;
  }
  for(int i = 0;i < m;i ++)
    cnt[i] += Map[pos][i];
  return flag;
}


int main()
{
  while(cin >> n >> m)
  {
    memset(cnt,0,sizeof(cnt));
    for(int i = 0;i < n;i ++)
    {
      string s;
      cin >> s;
      for(int j = 0;j < s.size();j ++)
      {
        if(s[j] == '0')
          Map[i][j] = 0;
        else Map[i][j] = 1;
        cnt[j] += Map[i][j];
      }
    }
    int flag = 0;
    for(int i = 0;i < n;i ++)
    {
      if(judge(i))
      {
        flag = 1;
        break;
      }
    }
    if(flag)
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
