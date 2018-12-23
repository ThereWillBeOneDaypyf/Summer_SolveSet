#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;


long long pow_mod(long long a,int x,long long m = MOD)
{
  if(!x)
    return 1;
  long long temp = pow_mod(a, x / 2);
  temp = temp * temp % m;
  if(x % 2)
    temp *= a;
  temp %= m;
  return temp;
}

long long Fermat(long long a, long long p){//费马求a关于b的逆元 
  return pow_mod(a, p-2, p);
}

int main()
{
  int n;
  while(cin >> n)
  {
    vector<int> G[2];
    bool stop = false;
    long long sum = 0;
    for(int i = 0;i < n;i ++)
    {
      int ty,val;
      cin >> ty >> val;
      if(ty == 1)
        stop = true;
      G[--ty].push_back(val);
      sum += val;
    }
    if(!stop)
      cout << -1 << endl;
    else 
    {
      sum *= Fermat(G[0].size(),MOD);
      sum %= MOD;
      cout << sum << endl;
    }
  }
}