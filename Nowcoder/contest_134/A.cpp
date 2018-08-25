#include <bits/stdc++.h>
using namespace std;

long long solve(set<pair<long long, int>> &s)
{
  if (s.size() < 3)
    return -1;
  auto a = s.begin();
  auto b = s.begin();
  auto c = s.begin();
  b++;
  c++;
  c++;
  long long ans = -1;
  while (c != s.end())
  {
    if ((*a).first + (*b).first > (*c).first)
    {
      ans = (*a).first + (*b).first + (*c).first;
    }
    a++;
    b++;
    c++;
  }
  return ans;
}

int main()
{
  int n, q;
  while (cin >> n >> q)
  {
    vector<pair<long long, int>> v;
    set<pair<long long, int>> s;
    for (int i = 1; i <= n; i++)
    {
      int x;
      cin >> x;
      v.push_back(make_pair(x, i));
      s.insert(make_pair(x, i));
    }
    set<int> id;
    map<int, long long> mem_ans;
    long long ans = -1;
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 2; i--)
    {
      if (v[i].first < v[i - 1].first + v[i - 2].first)
      {
        // cout << v[i].first << " " << v[i - 1].first << " " << v[i -2].first << endl;
        ans = v[i].first + v[i - 1].first + v[i - 2].first;
        id.insert(v[i].second);
        id.insert(v[i - 1].second);
        id.insert(v[i - 2].second);
        break;
      }
    }
    for (int i = 0; i < q; i++)
    {
      int x;
      cin >> x;
      if (n <= 3)
        cout << -1 << endl;
      else
      {
        if(id.empty())
        {
          cout << -1 << endl;
          continue;
        }
        if (!id.count(x))
        {
          cout << ans << endl;
        }
        else
        {
          if (mem_ans.count(x))
            cout << mem_ans[x] << endl;
          else
          {
            auto temp = *s.begin();
            for (auto it = s.begin(); it != s.end(); it++)
            {
              if ((*it).second == x)
              {
                temp = *it;
                s.erase(it);
                break;
              }
            }
            mem_ans[x] = solve(s);
            s.insert(temp);
            cout << mem_ans[x] << endl;
          }
        }
      }
    }
  }
}