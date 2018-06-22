#include<bits/stdc++.h>
using namespace std;

set<int> pow2;

void init()
{
  for(int i = 0;i < 31;i ++)
    pow2.insert(1LL << i);
}

bool judge(int x,int y)
{
  if(pow2.find(abs(x - y)) != pow2.end())
    return true;
  return false;
}

int main()
{
  int n;
  init();
  while(scanf("%d",&n) == 1)
  {
    vector<int> v;
    set<int> s;
    for(int i = 0;i < n;i ++)
    {
      int x;
      scanf("%d",&x);
      v.push_back(x);
      s.insert(x);
    }
    int ans = 0;
    vector<int> fi;
    if(!ans)
    {
      fi.push_back(v[0]);
      ans = 1;
    }
    if(ans)
    {
      for(int i = 0;i < n;i ++)
      {
        for(int j = 0;j < 31;j ++)
        {
          int x = v[i];
          int y = v[i] + (1 << j);
          if(ans == 2)
            break;
          if(s.find(x) != s.end() && s.find(y) != s.end())
          {
            if(judge(x,y))
            {
              fi.clear();
              fi.push_back(x);
              fi.push_back(y);
              ans = 2;
              break;
            }
          }
        }
      }
    }
    if(ans == 2)
    {
    for(int i = 0;i < n;i ++)
    {
        if(ans == 3)
            break;
      for(int j = 0;j < 31;j ++)
      {
          if(ans == 3)
            break;
        for(int k = j + 1;k < 31;k ++)
        {
          int x = v[i];
          int y = v[i] + (1 << j);
          int z = v[i] + (1 << k);
          if(ans == 3)
            break;
          if(s.find(y) != s.end() && s.find(z) != s.end())
          {
            if(judge(x,y) && judge(x,z) && judge(y,z))
            {
                fi.clear();
              fi.push_back(x);
              fi.push_back(y);
              fi.push_back(z);
              ans = 3;
              // fi.emplace_back({x,y,z});
              break;
            }
          }
        }
      }
    }
    }

    // cout << ans << endl;
    printf("%d\n",ans);
    for(auto ele : fi)
        printf("%d ",ele);
    //   cout << ele << " ";
    printf("\n");
    // cout << endl;
  }
}