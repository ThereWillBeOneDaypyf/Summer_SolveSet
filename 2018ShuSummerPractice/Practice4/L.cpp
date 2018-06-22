#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 7;
const int INF = 1e9 + 7;

vector<pair<int,int> > G[N];

void init()
{
    for(int i = 0;i < N;i ++)
        G[i].clear();
}

void add_edge(int u,int v,int val)
{
    G[u].push_back(make_pair(v,val));
}

int vis[N];
int dis[N];
int MAX;

void spfa()
{
    queue<int> q;
    for(int i = 0;i <= MAX;i ++)
        dis[i] = -INF;
    dis[0] = 0;
    q.push(0);
    vis[0] = 1;
    while(!q.empty())
    {
        auto u= q.front();
        q.pop();
        vis[u] = 0;
        for(auto temp : G[u])
        {
            int v = temp.first;
            int d = temp.second;
            if(dis[u] + d > dis[v])
            {
                dis[v] = dis[u] + d;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}


int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        init();
        MAX = 0;
        for(int i = 0;i < n;i ++)
        {
            int u,v,val;
            scanf("%d%d%d",&u,&v,&val);
            MAX = max(MAX,v + 1);
            add_edge(u,v + 1,val);
        }
        for(int i = 1;i <= MAX;i ++) 
            add_edge(i - 1,i,0),add_edge(i,i - 1,-1);
        spfa();
        printf("%d\n",dis[MAX]);
    }
}