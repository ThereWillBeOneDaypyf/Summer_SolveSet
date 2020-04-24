#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int> > v;
        vector<int> vis(n + 1);
        for(int i = 1; i <= n; i ++)
        {
            int x;
            cin >> x;
            v.push_back(make_pair(i, x));
        }
        sort(v.begin(), v.end(), [&](pair<int, int>a, pair<int, int> b) {
            return a.second < b.second;
        });
        bool flag = true;
        int gap = 0;
        bool is_end = false;
        vis[v[0].first] = 1;
        int cur = n;
        if(vis[n])
            is_end = true;
        for(int i = 1; i < v.size(); i ++)
        {
            // cout << "i: " << i << endl;
            if(is_end)
            {
                // cout << "in is end" << endl;
            }
            else 
            {
                // cout << v[i - 1].first << " " << v[i].first << endl;
                if(v[i].first - 1 != v[i - 1].first)
                {
                    flag = false;
                    break;
                }
            }
            while(cur > 0 && vis[cur] > 0)
                cur --;
            vis[v[i].first] = 1;
            // cout << "judge end: " << cur << endl;
            is_end = (v[i].first == cur);
        }
        if(flag)
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
}

