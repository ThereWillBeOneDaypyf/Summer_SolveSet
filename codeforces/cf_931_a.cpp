#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a,b;
  while(cin >> a >> b)
  {
    int dis = max(a,b) - min(a,b);
    int part1 = dis / 2;
    int part2 = dis - part1;
    cout << (part1 + 1) * part1 / 2 + (part2 + 1) * part2 / 2 << endl; 
  }
}