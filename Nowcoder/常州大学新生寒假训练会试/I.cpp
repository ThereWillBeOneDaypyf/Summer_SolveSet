#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<pair<int, int>> G[N];
int Index = 0;
int cnt = 0;
int dfn[N], low[N], instack[N];
stack<int> st;
int belong[N];
int n;
void init()
{
    for (int i = 0; i < N; i++)
        G[i].clear();
    Index = 0;
    cnt = 0;
    memset(dfn, 0, sizeof(dfn));
    while (!st.empty())
        st.pop();
    memset(instack, 0, sizeof(instack));
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++Index;
    st.push(u);
    instack[u] = 1;
    for (auto temp : G[u])
    {
        vector<int> edge{temp.first, temp.second};
        for (int i = 0; i < 2; i++)
        {
            int v = edge[i];
            if (!dfn[v])
            {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
            else if (instack[v])
                low[u] = min(low[u], dfn[v]);
        }
    }
    int x;
    if (dfn[u] == low[u])
    {
        cnt++;
        do
        {
            x = st.top();
            st.pop();
            instack[x] = 0;
            belong[x] = cnt;
        } while (x != u);
    }
}
void solve()
{
    for(int i = 1;i <= n;i ++)
        if(!dfn[i])
            tarjan(i);
}
vector<pair<int,int> > VG[N];
bool has[N];
int deg[N];
bool met[N];
void dfs(int u,int flag)
{
    if(met[u] && has[u])
        return;
    if(flag)
        has[u] = 1;
    if(has[u])
        flag = 1;
    met[u] = 1;
    if(!has[u] && !flag)
    {
        for(auto temp : VG[u])
        {
            if(temp.first == -1 || temp.second == -1)
                continue;
            dfs(temp.first,0);
            dfs(temp.second,0);
            if(has[temp.first] && has[temp.second])
            {
                flag = 1,has[u] = 1;
                break;
            }
        }
    }
    if(flag)
    {
        for(auto temp : VG[u])
        {
            if(temp.first != -1)            
            {
                dfs(temp.first,1);
            }
            if(temp.second != -1)
            {
                dfs(temp.second,1);
            }
        }
    }
}
void init_ans()
{
    memset(met,0,sizeof(met));
    for(int i = 1;i <= cnt;i++)
        if(!deg[i])
            dfs(i,has[i]);
    for(int i = 1;i <= cnt;i ++)
        if(!met[i])
            dfs(i,has[i]);
}
int main()
{
    ios :: sync_with_stdio(false);
    int m,k,q;
    while(cin >> n >> m >> k >> q)
    {
        init();
        for(int i = 0; i < m;i ++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            G[c].push_back(make_pair(a,b));
        }
        solve();
        for(int i = 0; i < N;i ++)
            VG[i].clear();
        for(int i = 1;i <= n;i ++)
        {
            for(auto temp : G[i])
            {
                int v1 = temp.first, v2 = temp.second;
                if(belong[v1] == belong[i])
                    v1 = -1;
                else
                    v1 = belong[v1],deg[v1] ++;
                if(belong[v2] == belong[i])
                    v2 = -1;
                else 
                    v2 = belong[v2],deg[v2] ++;
                VG[belong[i]].push_back(make_pair(v1,v2));
            }
        }
        memset(has,0,sizeof(has));
        for(int i = 0;i < k;i ++)
        {
            int x;
            cin >> x;
            has[belong[x]] = true;
        }
        init_ans();
        for(int i = 0;i < q;i++)
        {
            int x;
            cin >> x;
            if(has[belong[x]])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}