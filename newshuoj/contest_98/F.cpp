#include<bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int x,y;
    cin >> x >> y;
    int cnt = 0;
    int save = 0;
    if(!x || !y)
    {
      cout << 0 << endl;
      continue;
    }
    else if(x == 1 && y == 1)
    {
      cout << 0 << endl;
      continue;
    }
    while(1)
    {
      
      save ++;
      x -= 2;
      y -= 2;
      if(x <= 0)
      {
        if(save)
        {
          save --;
          x += 3;
        }
        else break;
      }
      if(y <= 0)
      {
        if(save)
        {
          save --;
          y += 3;
        }
        else break;
      }
      cnt ++;
    }
    cout << cnt + 1 << endl;
  }
}