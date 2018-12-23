#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  string s;
  while(cin >> n >> k >> s)
  {
    vector<int> cnt(k,0);
    for_each(s.begin(),s.end(),[&](char x) { cnt[x - 'A'] ++; });
    cout << (*min_element(cnt.begin(),cnt.end())) * k << endl;
  }
}