#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1415926535;
const double eps = 1e-6;

bool checkInView(int x,int y, int cx, int cy, int alpha, int cr)
{
    double ang = atan2(y - cy, x - cx) / PI * 180;
    if(ang < 0)
        ang += 360;
    double d = abs(ang - (double)alpha);
    if(d > 180)
        d = 360 - d;
    return d < cr || (abs(d - cr) < eps);
    // if(cr == 0)
    //     return false;
    // int tx = x - cx;
    // int ty = y - cy;
    // long double t_alpha;
    // // cout << "===> check: " << tx << " " << ty << endl;
    // if(tx == 0)
    // {
    //     if(ty >= 0)
    //         t_alpha = 90;
    //     else 
    //         t_alpha = 270;
    // }
    // else 
    // {
    //     t_alpha = atan2(abs((1.0 * ty)), abs((1.0 * tx))) * (180 / PI);
    // }
    // if(ty == 0)
    // {
    //     if(tx >= 0)
    //         t_alpha = 0;
    //     else t_alpha = 180;
    // }
    // else if(tx > 0 && ty < 0)
    // {
    //     t_alpha = 360 - t_alpha;
    // }
    // else if(tx < 0 && ty > 0)
    // {
    //     t_alpha = 180 - t_alpha;
    // }
    // else if(tx < 0 && ty < 0)
    // {
    //     t_alpha = 180 + t_alpha;
    // }
    // // cout << t_alpha << " " << alpha << " " << cr << endl;
    // if(alpha + cr > 360)
    // {
    //     return (0 <= t_alpha && t_alpha <= alpha + cr - 360) || (alpha - cr <= t_alpha && t_alpha <= 360);  
    //     // return (eps <= abs(t_alpha) && abs(t_alpha - alpha - cr + 360) <= eps) || (abs(alpha - cr - t_alpha) <= eps && abs(t_alpha - 360) <= eps);
    // }
    // else if(alpha - cr < 0)
    // {
    //     return (0 <= t_alpha && t_alpha <= alpha + cr) || (alpha - cr + 360 <= t_alpha && t_alpha <= 360);
    //     // return (eps <= abs(t_alpha) && abs(t_alpha - alpha - cr) <= eps) || (abs(alpha - cr + 360 - t_alpha) <= eps && abs(t_alpha - 360) <= eps);
    // }
    // else
    // //  <= eps;
    //     return alpha - cr <= t_alpha && t_alpha <= alpha + cr;
}

struct Node
{
    int x, y, a, r;
};
const int N = 3e4;
int deg[N];
vector<int> G[N];

void addEdge(int u, int v)
{
    G[u].push_back(v);
    deg[v] ++;
}

void topu(const vector<Node>& v)
{
    memset(deg, 0, sizeof(deg));
    for(int i = 0; i < N; i ++)
        G[i].clear();
    for(int i = 0; i < v.size();i ++)
    {
        for(int j = 0; j < v.size(); j ++)
        {
            if(i == j)
                continue;
            if(checkInView(v[i].x, v[i].y, v[j].x, v[j].y, v[j].a, v[j].r))
            {
                addEdge(j, i);
                // cout << j << " " << i << endl;
            }
        }
    }
    vector<int> ans;
    bool ok = true;
    for(int i = 0;i < v.size(); i ++)
    {
        bool flag = false;
        for(int j = 0;j < v.size();j ++)
        {
            if(!deg[j])
            {
                ans.push_back(j + 1);
                for(auto v : G[j])
                {
                    deg[v] --;
                }
                deg[j] --;
                flag = true;
                break;
            }
        }
        if(!flag)
            ok = false;
    }
    if(!ok)
        cout << -1 << endl;
    else 
    {
        for(int i = 0; i < v.size(); i ++)
        {
            if(i)
                cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
}

int main()
{
    int n;
    while(cin >> n)
    {
        vector<Node> v;        
        for(int i = 0;i < n; i ++)
        {
            int x, y, a, r;
            cin >> x >> y >> a >> r;
            v.push_back({x, y, a, r});
        }
        topu(v);
    }
}