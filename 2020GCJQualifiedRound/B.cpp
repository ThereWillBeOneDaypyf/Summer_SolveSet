#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int ka = 0;
    while(T--)
    {
        string s;
        cin >> s;
        vector<int> v;
        for(auto x : s)
            v.push_back(x - '0');
        string res = "";
        stack<int> st;
        for(int i = 0;i < v.size(); i ++)
        {
            while(st.size() < v[i])
            {
                st.push(1);
                res += "(";
            }
            while(st.size() > v[i]) 
            {
                st.pop();
                res += ")";
            }
            res += s[i];
        }
        while(!st.empty())
        {
            res += ")";
            st.pop();
        }
        cout << "Case #" << ++ ka << ": " << res << endl; 
    }
}