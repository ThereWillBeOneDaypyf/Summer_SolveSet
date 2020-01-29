#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int ans[N];

int main()
{
    string s;
    int n;
    while(cin >> n >> s)
    {
        stack<int> st;
        string num_str = "";
        for(int i = 0;i < s.size(); i ++)
        {
            if(s[i] == '(' || s[i] == ')')
            {
                if(num_str.length() > 0)
                {
                    int cur = atoi(num_str.c_str());
                    num_str = "";
                    if(st.empty())
                    {
                        ans[cur] = 0;
                    }
                    else
                    {
                        ans[cur] = st.top();
                    }
                    st.push(cur);
                }
                if(s[i] == ')')
                    st.pop();
            }
            else 
            {
                num_str += s[i];
            }
        }
        if(*s.rbegin() != ')')
        {
            int cur = atoi(num_str.c_str());
            if(st.empty())
                ans[cur] = 0;
            else ans[cur] = st.top();
        }
        for(int i = 1; i <= n; i ++)
        {
            cout << ans[i];
            if(i != n)
                cout << " ";
            else
                cout << endl;
        }
    }
}
