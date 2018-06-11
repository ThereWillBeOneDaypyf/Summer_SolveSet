#include<bits/stdc++.h>
using namespace std;


map<int,int> cnt1;
map<int,int> cnt2;
vector<int> v1;
vector<int> v2;
int n,m;
int ans = 0;
void init()
{
  v1.clear();
  v2.clear();
  cnt1.clear();
  cnt2.clear();
  ans = 0;
}
void dfs1(int pos,int cur)
{
  if(cur > m)
    return;
  if(pos >= v1.size())
  {
    cnt1[cur] ++;
    return;
  }
  dfs1(pos + 1,cur);
  dfs1(pos + 1,cur + v1[pos]);
}

void dfs2(int pos,int cur)
{
  if(cur > m)
    return;
  if(pos >= v2.size())
  {
    cnt2[cur] ++;
    return;
  }
  dfs2(pos + 1,cur);
  dfs2(pos + 1,cur + v2[pos]);
}

int main()
{
  while(scanf("%d%d",&n,&m) == 2)
  {
    init();
    for(int i = 0;i < n;i ++)
    {
      int v;
      scanf("%d",&v);
      if(v >= n / 2)
        v2.push_back(v);
      else v1.push_back(v);
    }
    dfs1(0,0);
    dfs2(0,0);
    for(auto temp1 : cnt1)
    {
      for(auto temp2 : cnt2)
      {
        if(temp1.first + temp2.first <= m)
        {
          ans += temp1.second * temp2.second;
        }
        else break;
      }
    }
    printf("%d\n",ans);
  }
}