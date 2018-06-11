#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  while(cin >> n)
  {
    int dif1 = (int)ceil(1.0 * n * 0.1) - (int)floor(1.0 * n * 0.1);
    int dif2 = (int)ceil(1.0 * n * 0.2) - (int)floor(1.0 * n * 0.2);
    int dif3 = (int)ceil(1.0 * n * 0.3) - (int)floor(1.0 * n * 0.3);
    cout << dif1 << " " << dif2 + dif1 << " " << dif3 + dif2 + dif1 << endl;
  }
}