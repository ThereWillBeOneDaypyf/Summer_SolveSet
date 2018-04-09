#include<bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    string s1,s2;
    cin >> s1 >> s2;
    s2 += s1;
    s2[0] = toupper(s2[0]);
    cout << s2 << endl;
  }
}