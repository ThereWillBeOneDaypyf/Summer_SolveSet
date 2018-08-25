#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7; 

int a[N]; 
int n;

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    cin >> n;
    for(int i = 0;i < n;i ++)
      cin >> a[i];
    stack<pair<int,int> > st;
    vector<int> ans;
    for(int i = n - 1;i >= 0;i --)
    {
      while(!st.empty())
      {
        auto temp = st.top();
        if(temp.first < a[i])
          st.pop();
        else 
        {
          ans.push_back(temp.second - i);
          break;
        }
      }
      if(st.empty())
        ans.push_back(0);
      st.push(make_pair(a[i],i));
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0;i < ans.size();i ++)
    {
      if(i)
        cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
}