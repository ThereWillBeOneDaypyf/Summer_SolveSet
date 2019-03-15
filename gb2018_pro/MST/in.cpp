#include<bits/stdc++.h>
using namespace std;

random_device rd;

struct Edge
{
  int u,v,d;
  Edge(int n)
  {
    u = rd() % n + 1;
    v = rd() % n + 1;
    d = rd() % ((int)1e9) + 1;
  }
  friend ostream& operator <<(ostream& os,const Edge& e)
  {
    os << e.u << " " << e.v << " " << e.d << endl;
  }
};

string getname(int cur)
{
  string name = std::to_string(cur) + ".in";
  return name;
}

int main()
{
  int cur = 1;
  freopen("1.in","w",stdout);
  int n;
  int k,m;
  string name;
  for(int i = 1;i <= 20;i ++)
  {
    if(i % 5 == 0)
    {
      cur ++;
      fclose(stdout);
      name = getname(cur);
      freopen(name.c_str(),"w",stdout);
    }
    n = rd() % 10000 + i + 1;
    k = i;
    m = rd() % 10000 + 1;
    cout << n << " " << i << " " << m << endl;
    for(int i = 1;i <= n;i ++)
    {
      cout << (rd() % k) + 1;
      if(i != n)
        cout << " ";
      else cout << endl;
    }
    for(int j = 0;j < m;j ++)
    {
      Edge e(n);
      cout << e;
    }
  }
  // fclose(stdout);
  // cur ++;
  // freopen(name.c_str(),"w",stdout);
  for(int i = 1;i <= 30;i ++)
  {
    if(i % 1 == 0)
    {
      cur ++;
      name = std::to_string(cur) + ".in";
      fclose(stdout);
      freopen(name.c_str(),"w",stdout); 
    }
    if(i <= 5)
      n = rd() % (int)1e5 + 1;
    else n = 1e6;
    if(i <= 5)
      k = (rd() % n) + 1;
    else k = (rd() % (int)1e4) + 1;
    if(i <= 5)
      m = rd() % (int)(1e5) + 1;
    else 
      m = rd() % (int)3e4 + 1;
    cout << n << " " << k << " " << m << endl;
    for(int i = 1;i <= n;i ++)
    {
      cout << (rd() % k) + 1;
      if(i == n)
        cout << endl;
      else cout << " ";
    }
    for(int j = 0;j < m;j ++)
    {
      Edge e(n);
      cout << e;
    }
  }
}
