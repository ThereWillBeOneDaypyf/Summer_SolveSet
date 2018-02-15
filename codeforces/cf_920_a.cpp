#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e3;

int vis[N];
int change[N];
int n,k;
bool judge()
{
    for(int i = 1;i <= n;i ++)
        if(!vis[i])
            return false;
    return true;
}
int main()
{
    ios :: sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> k;
        memset(vis,0,sizeof(vis));
        memset(change,0,sizeof(change));
        for(int i = 0;i < k;i++)
        {
            int pos;
            cin >> pos;
            vis[pos] = 1;
            change[pos] = 1;
        }
        int cnt = 1;
        while(!judge())
        {
            cnt ++;
            for(int i = 1;i <= n;i ++)
            {
                if(!vis[i] && vis[i + 1] && change[i + 1])
                    vis[i] = 1;
                else if(!vis[i] && vis[i - 1] && change[i - 1])
                    vis[i] = 1;
            }
            for(int i = 1;i <= n;i ++)
                change[i] = vis[i];
        }
        cout << cnt << endl;
    }
}