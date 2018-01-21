#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
struct Node
{
    int speed;
    int kind, damage;
};
vector<Node> v;
int vis[N];
int main()
{
    ios ::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        v.clear();
        memset(vis, 0, sizeof(vis));
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int s, k;
            cin >> s >> k;
            int dam = 0;
            if (k == 1 || k == 2)
                cin >> dam;
            v.push_back({s, k, dam});
        }
        stack<Node> st;
        for (int i = 0; i != v.size(); i++)
        {
            if(vis[i])
                continue;
            st.push(v[i]);
            int p = i + 1;
            while(p < v.size() && v[p - 1].speed <= v[p].speed)
            {
                vis[p] = 1;
                st.push(v[p++]);
            }
            bool flag = false;
            while(!st.empty())
            {
                auto temp = st.top();
                st.pop();
                if(flag)
                    continue;
                if(temp.kind == 3)
                    flag = 1;
                else if(temp.kind == 4)
                {
                    if(!st.empty())
                        st.pop();
                }
                else if(temp.kind == 2)
                {
                    ans += 1LL * (st.size() + 1) * temp.damage;
                } 
                else
                    ans += 1LL * temp.damage;
            }
        }
        cout << ans << endl;
    }
}