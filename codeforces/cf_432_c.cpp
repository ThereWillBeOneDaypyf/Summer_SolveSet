#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

bool vis[N];
int a[N];
int pos[N];
vector<int> pri;
int n;

void debug();

void init()
{
  memset(vis,0,sizeof(vis));
  vis[0] = vis[1] = 1;
  pri.clear();
  for(int i = 2;i < N;i ++)
  {
    if(vis[i])
      continue;
    pri.push_back(i);
    for(int j = 2;j * i < N;j ++)
      vis[i * j] = 1;
  }
}

random_device rd;

void change_pos(int index_i,int index_j)
{
  // debug();
  // cout << index_i << " " << index_j << endl;
  swap(a[index_i],a[index_j]);
  swap(pos[a[index_i]],pos[a[index_j]]);
  // debug();
}

bool find_num(int val,vector<pair<int,int> >& ans)
{
  int dis = pos[val] - val + 1;
  // cout << " find_num " << endl;
  // cout << val << " " << dis << endl;
  if(!vis[dis])
  {
    ans.push_back(make_pair(val,pos[val]));
    // cout << val << " " << pos[val] << endl;
    // assert(val < pos[val]);
    change_pos(pos[val],val);
  }
  else
  {
    bool flag = false;
    if(dis % 2)
    {
      ans.push_back(make_pair(pos[val] - 1,pos[val]));
      change_pos(pos[val],pos[val] - 1);
      dis --;
    }
    ans.push_back(make_pair(pos[val] - 1,pos[val]));
    change_pos(pos[val],pos[val] - 1);
    auto st = upper_bound(pri.begin(),pri.end(),dis) - pri.begin();
    for(int i = 0;i < st;i ++)
    {
      int left = i;
      if(!vis[dis - pri[left]])
      {
        flag = true;
        int index_i = val + pri[left] - 1;
        int index_j = index_i + dis - pri[left] - 1;
        // assert(index_i < index_j);
        // assert(val < index_i);
        // cout << val << "  " << index_i << " " << index_j << endl;
        // if(index_i > index_j)
          // swap(index_i,index_j);
        change_pos(index_i,index_j);
        change_pos(val,index_i);
        // cout << val << " " << index_i << " " << index_j << endl;
        ans.push_back(make_pair(index_i,index_j));
        ans.push_back(make_pair(val,index_i));
        break;
      }
    }
    if(!flag)
    {
      // cout << " ????? " << endl;
      return false;
    }
  }
  return true;
}

void debug()
{
  cout << " a[n] : " << endl;
  for(int i = 1; i <= n;i ++)
    cout << a[i] << " ";
  cout << endl;
  cout << " pos[n] : " << endl;
  for(int i = 1;i <= n;i ++)
    cout << pos[i] << " " ;
  cout << endl;
}

int main()
{
  ios :: sync_with_stdio(false);
  init();
  while(cin >> n)
  {
    for(int i = 1;i <= n;i ++)
    {
      cin >> a[i];
      // a[i] = n - i + 1;
      pos[a[i]] = i;
    }
    vector<pair<int,int> > ans;
    for(int i = 1;i <= n;i ++)
    {
      // debug();
      if(pos[i] == i)
        continue;
      if(!find_num(i,ans))
        break;
    }
    cout << ans.size() << endl;
    for(auto pr : ans)
      cout << pr.first << " " << pr.second << endl;
  }
}