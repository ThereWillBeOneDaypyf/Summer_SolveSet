#include<bits/stdc++.h>
using namespace std;


int main()
{
  double n,m;
  while(cin >> n >> m)
  {
    double l1 = log2(1.0 * n);
    double l2 = log2(1.0 * m);
    double ans1 = 1.0 * m *  l1, ans2 = 1.0 * n * l2;
    if(n == m)
      cout << "=" << endl;
    else if(ans1 == ans2)
      cout << "=" << endl;
    else if(ans1 < ans2)
      cout << "<" << endl;
    else cout << ">" << endl;
  }
}