#include<bits/stdc++.h>
using namespace std;

struct Node
{
    long long s_cnt = 0,t_cnt = 0;
    string s = "";
    Node(long long _s_cnt,long long _t_cnt,string _s) : s_cnt(_s_cnt),t_cnt(_t_cnt),s(_s){}
    bool operator < (const Node rhs) const
    {
        return s_cnt * rhs.t_cnt > t_cnt * rhs.s_cnt;
    }
};

int main()
{
    ios :: sync_with_stdio(false);
    int n;
    while(cin >> n)
    {
        vector<Node> v;
        for(int i = 0;i < n;i ++)
        {
            string s;
            cin >> s;
            int s_cnt = 0,t_cnt = 0;
            for(auto ele : s)
            {
                if(ele == 's')
                    s_cnt ++;
                else
                    t_cnt ++;
            }
            v.push_back((Node){s_cnt,t_cnt,s});
        }
        sort(v.begin(),v.end());
        string ans_s = "";
        for(auto temp : v)
            ans_s += temp.s;
        int cnt = 0;
        long long ans = 0;
        for(auto ele : ans_s)
        {
            if(ele == 's')
                cnt ++;
            else
                ans += cnt;
        }
        cout << ans << endl;
    }
}