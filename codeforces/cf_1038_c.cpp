#include <bits/stdc++.h>
using namespace std;

long long sum[2];
multiset<int> s[2];
void remove_op(int myID, int opID)
{
  s[opID].erase(s[opID].find(*(s[opID].rbegin())));
}

void add_my(int myID, int opID)
{
  sum[myID] += *s[myID].rbegin();
  s[myID].erase(s[myID].find(*(s[myID].rbegin())));
}

int main()
{
  int n;
  while (cin >> n)
  {
    for (int j = 0; j < 2; j++)
    {
      s[j].clear();
      for (int i = 0; i < n; i++)
      {
        int x;
        cin >> x;
        s[j].insert(x);
      }
    }
    memset(sum, 0, sizeof(sum));
    while (!s[0].empty() || !s[1].empty())
    {
      for (int i = 0; i < 2; i++)
      {
        int myID = i;
        int opID = (i + 1) % 2;
        if (s[myID].empty())
        {
          remove_op(myID,opID);
        }
        else if (s[opID].empty())
        {
          add_my(myID,opID);
        }
        else
        {
          if(*s[myID].rbegin() > *s[opID].rbegin())
            add_my(myID,opID);
          else remove_op(myID,opID);
        }
      }
    }
    cout << sum[0] - sum[1] << endl;
  }
}