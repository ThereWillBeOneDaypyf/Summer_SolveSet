#include<bits/stdc++.h>
using namespace std;


int main()
{
  string s;
  while(cin >> s)
  {
    map<char,int> cnt;
    for(auto x : s)
      cnt[x] ++;
    if(cnt.size() < 2 || cnt.size() > 4)
      cout << "No" << endl;
    else if(cnt.size() == 4)
      cout << "Yes" << endl;
    else 
    {
      int flag = 0;
      for(auto temp : cnt)
        if(temp.second >= 2)
          flag ++;
      if(flag + cnt.size() >= 4)
        cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}