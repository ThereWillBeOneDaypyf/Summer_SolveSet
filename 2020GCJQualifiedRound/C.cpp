#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int st, ed, id;
};

int main()
{
    int T;
    cin >> T;
    int ka = 0;
    while(T--)
    {
        int n;
        cin >> n;
        vector<Node> v;
        for(int i = 0; i < n; i ++)
        {
            int st, ed;
            cin >> st >> ed;
            v.push_back({st, ed, i});
        }
        sort(v.begin(), v.end(), [&](Node& x, Node& y){
            if(x.st != y.st)
                return x.st < y.st;
            return x.ed > y.ed;
        });
        int t[2] = {0, 0};
        char res[2] = {'C', 'J'};
        string ans = string(n, '0');
        bool flag = true;
        for(int i = 0; i < v.size(); i ++)
        {
            if(t[0] <= v[i].st)
            {
                t[0] = v[i].ed;
                ans[v[i].id] = res[0];
                continue;
            }
            if(t[1] <= v[i].st)
            {
                t[1] = v[i].ed;
                ans[v[i].id] = res[1];
                continue;
            }
            flag = false;
            break;
        }
        cout << "Case #" << ++ ka << ": ";
        if(!flag)
            cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
}