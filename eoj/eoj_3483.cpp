#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
struct Edge
{
    int u,v,d;
};
int fa[N];
void init()
{
    for(int i = 0;i < N;i++)
        fa[i] = i;
}
int find(int x)
{
    if(fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int a,int b)
{
    a = find(a), b = find(b);
    if(fa[a] != fa[b])
        fa[a] = fa[b];
}
bool judge(const vector<Edge> &e,int status,int st,int ed)
{
    init();
    for(auto edge : e)
    {
        int u = edge.u, v = edge.v, d = edge.d;
        if((d | status) == status)
            merge(u,v);
    }
    return find(st) == find(ed);
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        vector<Edge> v;
        for(int i = 0;i < m;i++)
        {
            int from,to,d;
            cin >> from >> to >> d;
            v.push_back({from,to,d});
        }
        int s,t;
        cin >> s >> t;
        int status = (1 << 10) - 1;
        if(!judge(v,status,s,t))
        {
            cout << -1 << endl;
            continue;
        }
        for(int i = 9;i >= 0;i--)
        {
            if(judge(v,status ^ (1 << i),s,t))
                status ^= (1 << i);
        }
        cout << status << endl;
    }
}