#include <bits/stdc++.h>
using namespace std;

map<int,int> pos;

int main()
{
  int n;
  while(cin >> n)
  {
    priority_queue<int, vector<int>, greater<int>> in_q;
    priority_queue<int> out_q;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      pos[x] = i + 1;
      in_q.push(x);
    }
    string s;
    cin >> s;
    for (int i = 0; i < 2 * n; i++)
    {
      if (s[i] == '0')
      {
        cout << pos[in_q.top()] << " ";
        out_q.push(in_q.top());
        in_q.pop();
      }
      else
      {
        cout << pos[out_q.top()] << " ";
        out_q.pop();
      }
    }
    cout << endl;
  }
}