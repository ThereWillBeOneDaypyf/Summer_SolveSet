#include<bits/stdc++.h>
using namespace std;

set<char> ss;
int k;
string s;
string ans;
int flag = 0;
void dfs(int pos,string &ans_s,bool eq)
{
    if(flag)
        return;
    if(pos >= k)
    {
        if(!eq)
        {
            ans = ans_s;
            flag = 1;
        }
        return;
    }
    if(pos >= s.size() || !eq)
    {
        ans_s.push_back(*ss.begin());
        dfs(pos + 1,ans_s,false);
        ans_s.pop_back();
    }
    else
    {
        ans_s.push_back(s[pos]);
        dfs(pos + 1,ans_s, true);
        ans_s.pop_back();
        auto p = ss.upper_bound(s[pos]);
        if(p != ss.end())
        {
            ans_s.push_back(*p);
            dfs(pos + 1,ans_s, false);
            ans_s.pop_back();
        }
    }
}

int main()
{
    int n;
    while(cin >> n >> k >> s)
    {
        ss.clear();
        flag = 0;
        for(auto ele : s)
            ss.insert(ele);
        string temp = "";
        dfs(0,temp,1);
        cout << ans << endl;
    }
}