#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e3;

int n, m;

int dp[N][N][26];
vector<pair<int, char>> G[N];
void init()
{
    for (int i = 0; i < N; i++)
        G[i].clear();
}
int dfs(int u, int v, int sta)
{
    if (dp[u][v][sta] != -1)
        return dp[u][v][sta];
    int res = 0;
    for (auto e : G[u])
    {
        int to = e.first;
        int d = e.second - 'a';
        if (d < sta)
            continue;
        res |= (dfs(v, to, d) ^ 1);
        if (res)
            break;
    }
    return dp[u][v][sta] = res;
}
void get_ans()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ans = dfs(i, j, 0);
            if (ans)
                cout << 'A';
            else
                cout << 'B';
        }
        cout << endl;
    }
}
int main()
{
    while (cin >> n >> m)
    {
        init();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < m; i++)
        {
            int u, v;
            char d;
            cin >> u >> v >> d;
            G[u].emplace_back(make_pair(v, d));
        }
        get_ans();
    }
}