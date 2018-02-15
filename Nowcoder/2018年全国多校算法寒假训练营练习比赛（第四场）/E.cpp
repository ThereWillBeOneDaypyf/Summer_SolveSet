#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...

#define N 1000
const int M = 1e6;

int instack[N];
int belong[N];
int dfn[N];
int low[N];
int head[N];
int ans[N];
int out[N];
int cnt = 0;
int Index = 0;
int tot = 0;
stack<int>st;
int n,m;
struct Edge
{
	int u,v,next;
}edge[M * 2];

void init()
{
	memset(edge,0,sizeof(edge));
	memset(ans,0,sizeof(ans));
	memset(instack,0,sizeof(instack));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(belong,0,sizeof(belong));
	memset(head,-1,sizeof(head));
	memset(out,0,sizeof(out));
	while(!st.empty())
		st.pop();
	tot = 0;
	Index = 0;
	cnt = 0;
}
void add_edge(int u,int v)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot;
	tot++;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++Index;
	st.push(u);
	instack[u] = 1;
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v = edge[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(instack[v])
			low[u] = min(low[u],dfn[v]);
	}
	int x;
	if(dfn[u]==low[u])
	{
		cnt ++ ;
		do{
			x =st.top();
			st.pop();
			instack[x] = 0;
			belong[x] = cnt;
		}while(x!=u);
	}
}
void solve()
{
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
}

int main()
{
    while(cin >> n >> m)
    {
        init();
        vector<int> root;
        for(int i = 0; i < m;i ++)
        {
            int x;
            cin >> x;
            root.push_back(x);
        }
        for(int i = 1;i <= n;i ++)
        {
            int num;
            cin >> num;
            for(int j = 0;j < num;j++)
            {
                int v;
                cin >> v;
                add_edge(i,v);
            }
        }
        solve();
        bool fuck[N];
        memset(fuck,0,sizeof(fuck));
        for(auto x : root)
        {
            fuck[belong[x]] = 1;
        }
        for(int i = 0;i < tot;i ++)
        {
            int u = edge[i].u, v = edge[i].v;
            if(belong[u] != belong[v])
                out[belong[v]] ++;
        }
        int flag = 1;
        set<int> ans;
        for(int i = 1;i <= cnt;i++)
        {
            if(out[i] == 0 && fuck[i] == 0)
            {
                flag = 0; 
                break;
            }
            else if(out[i] == 0)
                ans.insert(i);
        }
        if(!flag)
            cout << -1 << endl;
        else
            cout << ans.size() << endl;
    }
}