#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 7;

int vis[N];

void init()
{
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    vis[1] = 1;
    for(int i = 2; i < N; i ++) {
        if(vis[i])
            continue;
        for(int j = 2; i * j < N; j ++) {
            vis[i * j] = 1;
        }
    }
}

int main()
{
    int n;
    init();
    while(cin >> n) 
    {
        int ans = -1;
        for(int i = 2; i < n; i ++)
        {
            if(!vis[i] && !vis[n - i])
            {
                ans = i;
                break;
            }
        }     
        if(ans == - 1)
            cout << ans << endl;
        else cout << ans << " " << n - ans << endl;
    }
}