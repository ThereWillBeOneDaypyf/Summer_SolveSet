#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

string s;
int n,m;
vector<int> G[N];
int vis[N];
int cnt[N][26];
int ans = 0;

void init()
{
    for(int i = 0;i < N;i ++)
        G[i].clear();
    memset(vis,0,sizeof(vis));
    memset(cnt,-1,sizeof(cnt));
}

bool dfs(int u)
{
    if(vis[u] == -1)
        return false;
    if(vis[u] == 1)
        return true;
    for(int i = 0;i < 26;i ++)
        cnt[u][i] = 0;
    vis[u] = -1;
    int flag = 1;
    for(auto v : G[u])
    {
        flag &= dfs(v);
        for(int i = 0;i < 26;i ++)
            cnt[u][i] = max(cnt[u][i],cnt[v][i]);
    }
    cnt[u][s[u - 1] - 'a'] ++;
    // cout << " *** ** ** " << u << " ***** " << endl;
    for(int i = 0;i < 26;i ++)
    {
        ans = max(ans,cnt[u][i]);
        // cout << cnt[u][i] << " ";
    }
    // cout << endl;
    vis[u] = 1;
    return flag;
}

int main()
{
    while(cin >> n >> m)
    {
        init();
        cin >> s;
        for(int i = 0;i < m;i ++)
        {
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
        }
        bool flag = 1;
        ans = 0;
        for(int i = 1;i <= n;i ++)
        {
            if(!vis[i] && !dfs(i))
            {
                flag = 0; 
                break;
            }
        }
        if(!flag)
            cout << - 1 << endl;
        else cout << ans << endl;
    }
}